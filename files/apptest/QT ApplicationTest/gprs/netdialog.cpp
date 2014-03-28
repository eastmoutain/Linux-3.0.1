
#include "netdialog.h"
#include <qpushbutton.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qmultilineedit.h>
#include <qmessagebox.h>

NetDialog::NetDialog(QWidget * parent, const char * name, WFlags f):NetdialogForm(parent, name, f)
{
	m_startgprs = new QProcess;
	
	connect(start_Btn,SIGNAL(clicked()),this,SLOT(startbtnclicked()));
	connect(stop_Btn,SIGNAL(clicked()),this,SLOT(stopbtnclicked()));
	connect(m_startgprs, SIGNAL(readyReadStdout()), this, SLOT(readOutput()));
}

void NetDialog::startbtnclicked()
{
	::system("ifconfig eth0 down");
	::system("ifconfig lo down");

   m_startgprs->clearArguments();
  
   QString dialcmd=PPPPATH;
   dialcmd+="bin/pppd";

   QString dialParam1="call";

   
   QString  dialParam2="gprs";
   m_startgprs->addArgument(dialcmd);
   m_startgprs->addArgument(dialParam1);
   m_startgprs->addArgument(dialParam2);
   m_startgprs->start();

}

void NetDialog::readOutput()
{
	while (m_startgprs->canReadLineStdout()) 
     {
		QString gprsInfo = m_startgprs->readLineStdout();
		gprsInfo_LineEdit->append(gprsInfo);
	}
	int n=gprsInfo_LineEdit->numLines();
	bool mark=FALSE;
	gprsInfo_LineEdit->setCursorPosition(n,0,mark);
}

void NetDialog::stopbtnclicked()
{
	::system("killall pppd");
}
