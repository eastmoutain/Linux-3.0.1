
#include <qcheckbox.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qspinbox.h>
#include <unistd.h>
#include <stdlib.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qsocketnotifier.h>
#include <qpainter.h>
#include <qtopia/qpeapplication.h>
#include <qfileinfo.h>
#include <termio.h>
#include <qcombobox.h>

#include "gprs.h"

int m_fd;
QString num="";

TMainForm::TMainForm(QWidget * parent, const char * name, WFlags f) : TMainFormBase(parent, name, f), m_notifier(0)
{
	//num=telnum_LineEdit->text();
    connect(num1_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num2_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num3_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num4_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num5_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num6_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num7_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num8_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num9_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(num0_Btn,SIGNAL(clicked()),this,SLOT(numbtnclicked()));
    connect(call_Btn,SIGNAL(clicked()),this,SLOT(callbtnclcked()));
    connect(net_Btn,SIGNAL(clicked()),this,SLOT(netbtnclicked()));
    connect(listen_Btn,SIGNAL(clicked()),this,SLOT(listenbtnclicked()));
    connect(back_Btn,SIGNAL(clicked()),this,SLOT(backbtnclicked()));
    connect(mess_Btn,SIGNAL(clicked()),this,SLOT(messbtnclicked()));
    connect(stop_Btn,SIGNAL(clicked()),this,SLOT(stopbtnclicked()));
    connect (ok_Btn,SIGNAL(clicked()),this,SLOT(openMyCom()));
    connect(mini_Btn,SIGNAL(clicked()),this,SLOT(minibtnclicked()));
    connect(allmess_Btn,SIGNAL(clicked()),this,SLOT(allmessbtnclicked()));
  
}

TMainForm::~TMainForm()
{
	::system("killall pppd");

	if (m_fd >= 0) {
       ::close(m_fd);
       m_fd = -1;
     }
}
void TMainForm::minibtnclicked()
{
	this->hide();
}
void TMainForm::allmessbtnclicked()
{
	ScanMessDialog *wdg = new ScanMessDialog(this );
	if(QPEApplication::execDialog(wdg) == QDialog::Accepted)
   	{	
	}
	delete wdg;
}

void TMainForm::stopbtnclicked()
{
	::write(m_fd,"ATH\r",strlen("ATH\r"));
	sleep(1);	
	telnum_LineEdit->clear();
}

void TMainForm:: numbtnclicked()
{
	QPushButton *btn=(QPushButton*)sender();
	QString numValue=btn->text();
	telnum_LineEdit->setText(telnum_LineEdit->text()+numValue);
}


void  TMainForm::listenbtnclicked()
{
    ::write(m_fd,"ATA\r",strlen("ATA\r"));
    sleep(1);
    //qDebug()<<"a call is coming\n";
}

void TMainForm:: backbtnclicked()
{    
    
      telnum=telnum_LineEdit->text();
	 QString t = telnum.left(telnum.length()-1);
      telnum_LineEdit->setText(t);
}

void TMainForm:: callbtnclcked()
{    
	telnum=telnum_LineEdit->text();
     QString send="ATD"+telnum+";\r";
	
     if (telnum.isEmpty()) 
	{ 
		QMessageBox::information(this,"gprs","plesse input the address",0);
    		return ; 
     } 
	if(::write(m_fd, send.latin1(), send.length()))
	{
		stop_Btn->setEnabled(true);
		if(telnum_LineEdit->text().find("calling")==-1)
		{
			telnum_LineEdit->setText("calling "+telnum);
		}
	}
}

void  TMainForm::messbtnclicked()
{
	num=telnum_LineEdit->text();
	if(num=="")
	{
		QMessageBox::information(this,"gprs","plesse input the address",0);
	}
	else
	{
		MesDialog *wdg = new MesDialog(this );
		if(QPEApplication::execDialog(wdg) == QDialog::Accepted)
	   	{	
		}   
		delete wdg;
	}
}

void  TMainForm::netbtnclicked()
{
	NetDialog *wdg = new NetDialog(this );
	if(QPEApplication::execDialog(wdg) == QDialog::Accepted)
	{
	}
	delete wdg;
}

void TMainForm::remoteDataIncoming() 
{ 
	char getch[30];
	if(::read(m_fd,getch,30))
	{
		sleep(1);
		//QMessageBox::information(this,tr(""),tr(getch));
		QString mes_or_tell = QString(getch);
		//QMessageBox::information(this,"gprs",mes_or_tell,0);

		
		int tell_iscome=mes_or_tell.find(QRegExp("RING"), 0);
		int mes_iscome=mes_or_tell.find(QRegExp("CMTI"), 0);
		if(mes_iscome>=0)
		{
			QMessageBox::information(this,"gprs","message is received",0);
		}
		if(tell_iscome>=0)
		{
			QMessageBox::information(this,"gprs","tell is coming",0);
			listen_Btn->setEnabled(true);
			stop_Btn->setEnabled(true);
		}
	}

	

} 


void TMainForm::openMyCom()
{
    m_fd = openSerialPort();
    if (m_fd < 0) {
    QMessageBox::warning(this, tr("Error"), tr("Fail to open serial port!"));
    return ;
    }

    ::write(m_fd,"AT+CNMI=2,1,0,0,0\r",strlen("AT+CNMI=2,1,0,0,0\r"));
    sleep(1);
    speedComboBox->setEnabled(false);
    dataBitsComboBox->setEnabled(false);
    parityComboBox->setEnabled(false);
    stopBitsComboBox->setEnabled(false);
    portNameComboBox->setEnabled(false);
    ok_Btn->setEnabled(false);
    
    call_Btn->setEnabled(true);
    mess_Btn->setEnabled(true);
    allmess_Btn->setEnabled(true);

    m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this); 
    connect (m_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming())); 
    
 }

int TMainForm::openSerialPort()
{
  int fd = -1;

  portName=portNameComboBox->currentText();
  fd = ::open(portName, O_RDWR|O_NONBLOCK);
  if (fd < 0) {
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
        cfsetispeed(&serialAttr,B9600);
        cfsetospeed(&serialAttr,B115200);
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
  if (tcsetattr(fd, TCSANOW, &serialAttr) != 0) {
    QMessageBox::warning(this, tr("Error"), tr("fd2"));
    return -1;
  }
  return fd;
}







