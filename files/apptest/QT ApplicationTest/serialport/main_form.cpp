#include "main_form.h"
#include <qmultilineedit.h>
#include <qprogressbar.h>
#include <qtimer.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qstringlist.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>
#include <termio.h>
#include <qpushbutton.h>


TMainForm::TMainForm(QWidget * parent, const char * name, WFlags 
f):TMainFormBase(parent, name, f), m_notifier(0) 
{ 
	connect (sendMsgBtn,SIGNAL(clicked()),this,SLOT(sendButtonClicked()));
	connect (openMyComBtn,SIGNAL(clicked()),this,SLOT(openMyCom()));
	connect (closeMyComBtn,SIGNAL(clicked()),this,SLOT(closeMyCom()));
	closeMyComBtn->setEnabled(false);
	sendMsgBtn->setEnabled(false);
} 

void TMainForm::openMyCom() 
{
	m_fd = openSerialPort(); 
	if (m_fd < 0) 
	{ 
	QMessageBox::warning(this, tr("Error"), tr("Fail to open serial port!")); 
	return ; 
	} 
	openMyComBtn->setEnabled(false);
	closeMyComBtn->setEnabled(true);
	sendMsgBtn->setEnabled(true);
	speedComboBox->setEnabled(false);
	dataBitsComboBox->setEnabled(false);
	parityComboBox->setEnabled(false);
     stopBitsComboBox->setEnabled(false);
     portNameComboBox->setEnabled(false);

	m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this); 
	connect (m_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming())); 
}

void TMainForm::closeMyCom()
{
	if (m_notifier) 
	{ 
		delete m_notifier; 
		m_notifier = 0; 
	} 
 
	if (m_fd >= 0) 
	{ 
	     ::close(m_fd); 
	     m_fd = -1; 
	} 
	openMyComBtn->setEnabled(true);
     closeMyComBtn->setEnabled(false);
     sendMsgBtn->setEnabled(false);
     speedComboBox->setEnabled(true);
     dataBitsComboBox->setEnabled(true);
     parityComboBox->setEnabled(true);
     stopBitsComboBox->setEnabled(true);
     portNameComboBox->setEnabled(true);
}

TMainForm::~TMainForm() 
{ 
  
 
} 
 
void TMainForm::sendButtonClicked() 
{ 
	QString text( m_sendEdit->text() ); 
	if (text.isEmpty()) 
	{ 
		return ; 
	} 
	::write(m_fd, text.latin1(), text.length()); 
	m_sendEdit->setText(""); 
} 
 
 
int TMainForm::openSerialPort() 
{ 
	int fd = -1; 
 
	portName=portNameComboBox->currentText();
	fd = ::open(portName, O_RDWR|O_NONBLOCK); 
	if (fd < 0) 
	{ 
		QMessageBox::warning(this, tr("Error"), tr("fd1")); 
	    return -1; 
	} 
 
	termios serialAttr; 
	memset(&serialAttr, 0, sizeof serialAttr); 
/*  
serialAttr.c_iflag = IGNPAR; 
  serialAttr.c_cflag = B115200 | HUPCL | CS8 | CREAD | CLOCAL; 
  serialAttr.c_cc[VMIN] = 1; 
*/
	if(speedComboBox->currentText() == tr("9600"))
	{
        	cfsetispeed(&serialAttr,B9600);
		cfsetospeed(&serialAttr,B9600);
	}
   	else if(speedComboBox->currentText() == tr("115200"))
	{
		cfsetispeed(&serialAttr,B115200);        	
		cfsetospeed(&serialAttr,B115200);
	}
	else if(speedComboBox->currentText() == tr("4800"))
	{
		cfsetispeed(&serialAttr,B4800);        	
		cfsetospeed(&serialAttr,B4800);
	}
   	if(dataBitsComboBox->currentText() == tr("8"))
	{
        	serialAttr.c_cflag &= ~CSIZE;
		serialAttr.c_cflag |= CS8;
	}	
   	else if(dataBitsComboBox->currentText() == tr("7"))
       	 {
        	serialAttr.c_cflag &= ~CSIZE;
		serialAttr.c_cflag |= CS7;
	}
  	if(parityComboBox->currentText() == tr("No"))
        	serialAttr.c_iflag = IGNPAR;
	else if(parityComboBox->currentText() == tr("Odd"))
	{
        	serialAttr.c_cflag |= (PARODD | PARENB);
		serialAttr.c_iflag |= INPCK;
	}
   	else if(parityComboBox->currentText() == tr("Even"))
     {
        	serialAttr.c_cflag |= PARENB;
		serialAttr.c_cflag &= ~PARODD;
		serialAttr.c_iflag |= INPCK;
	}
	if (tcsetattr(fd, TCSANOW, &serialAttr) != 0) 
	{ 
	QMessageBox::warning(this, tr("Error"), tr("fd2")); 
     return -1; 
	} 
	return fd; 
} 
 
 
void TMainForm::remoteDataIncoming() 
{ 
	char c; 
	if (read(m_fd, &c, sizeof c) != 1) 
	{ 
		QMessageBox::warning(this, tr("Error"), tr("Receive error!")); 
		return; 
	} 
	m_receiveEdit->insert(QString(QChar(c))); 
} 
