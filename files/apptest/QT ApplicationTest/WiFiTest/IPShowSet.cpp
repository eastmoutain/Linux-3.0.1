


#include <qlabel.h> 
#include <qpushbutton.h> 
#include <qlayout.h> 
#include <qspinbox.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/ioctl.h> 
#include <fcntl.h> 
#include <qapplication.h> 
#include <qmessagebox.h>
#include <qpainter.h> 
#include <qmultilineedit.h>
#include <qtimer.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qlineedit.h>
#include "IPShowSet.h"

  
QIPShowSetDialog::QIPShowSetDialog(QWidget * parent, const char * name, WFlags f):QIPBaseForm(parent, name, f) 
{   

       m_strIP="";
       m_strGateway="";
       m_strFistDNS="";
       m_strSecondDNS="";

       m_cmdGateway = new QProcess;
       connect(m_cmdGateway, SIGNAL(readyReadStdout()), this, SLOT(readRouteOutput()));
       connect(m_btnOK, SIGNAL(clicked()), this, SLOT(OK()));
   
      //scanning wifi net 
      QTimer::singleShot(10, this, SLOT(startGetway()));
     

}
 QIPShowSetDialog::~QIPShowSetDialog() 
 {

    m_cmdGateway->tryTerminate();
    QTimer::singleShot(300, m_cmdGateway, SLOT( kill() ) );

   if(m_cmdGateway!=NULL)
     delete m_cmdGateway;


 } 

void QIPShowSetDialog::startGetway()
{

     m_cmdGateway->clearArguments();
     m_cmdGateway->addArgument("route");
     m_cmdGateway->addArgument("-n");
     m_cmdGateway->start();

}

void QIPShowSetDialog::readRouteOutput()
{

   while (m_cmdGateway->canReadLineStdout()) 
    {
        QString lineInfo =  m_cmdGateway->readLineStdout();
        
         
       int nIndex=lineInfo.find("0.0.0.0");

       if(nIndex!=-1)
        {
          QString temp=lineInfo.remove(0,strlen("0.0.0.0"));

          int nTempIndex=temp.find("0.0.0.0");

          QString strGatewag= temp.left(nTempIndex);

          qWarning(strGatewag);
          strGatewag.remove(0,8);  //remove "   "
    
         m_IP->setText(m_strIP);
         m_gateWay->setText(strGatewag);
         m_firstDNS->setText(m_strFistDNS);
         m_secondDNS->setText(m_strSecondDNS);
        

        }

     }

}
void QIPShowSetDialog::OK()
{

   QDialog::accept();

}



