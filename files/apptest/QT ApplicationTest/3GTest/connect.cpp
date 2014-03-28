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

#include "connect.h"

QString strModuleType;

QConnectForm::QConnectForm(QWidget * parent, const char * name, WFlags f):QDialup(parent, name, f) 
{   
       m_bConnect=false;
       m_cmdPrepare = new QProcess;
       m_cmdDialup = new QProcess;
   
       connect(m_ctlConnect, SIGNAL(clicked()), this, SLOT(runClicked()));
       connect(m_ctlMinimize, SIGNAL(clicked()), this, SLOT(runClicked()));
    
       connect(m_cmdPrepare, SIGNAL(readyReadStdout()), this, SLOT(readOutput()));
       connect(m_cmdDialup, SIGNAL(readyReadStdout()), this, SLOT(readOutput()));
       
       m_timer=new QTimer(this);
       connect(m_timer,SIGNAL(timeout()),this,SLOT(timeOut()));
}

 QConnectForm::~QConnectForm() 
 {
    m_cmdPrepare->tryTerminate();
    QTimer::singleShot( 3000, m_cmdPrepare, SLOT( kill() ) );
  
    m_cmdDialup->tryTerminate();
    QTimer::singleShot( 3000, m_cmdDialup, SLOT(kill()));

   if(m_cmdPrepare!=NULL)
     delete m_cmdPrepare;
   if(m_cmdDialup!=NULL)
     delete m_cmdDialup;
   if(m_timer==NULL)
     delete  m_timer;

 } 


void QConnectForm::runClicked()
{
  QPushButton* obj = (QPushButton*)sender();

  if (obj == m_ctlConnect){
    if(m_bConnect){ 
       m_cmdDialup->tryTerminate();
       QTimer::singleShot( 3000, m_cmdDialup, SLOT(kill()));

       m_bConnect=false;
       m_ctlMessage->clear();
       m_ctlMessage->append("Disconnect");

       m_ctlConnect->setText("Connect");
       return;
    }
   QString strNetType;
   
   if(m_nType==0 )
       strNetType = "Start connect WCDMA net, please wait......";
   else if(m_nType==1)
       strNetType = "Start connect CDMA2000, please wait......";
   else if(m_nType==2)
       strNetType = "Start connect TDSCDMA net, please wait......";

   m_ctlMessage->append(strNetType);
   m_ctlConnect->setEnabled(false);
   m_cmdPrepare->clearArguments();

   QFileInfo fiAD3812(ADFILE);
   if(fiAD3812.exists()&&m_nType==0)
    {
        SetConnectType(0,1);
        m_timer->start(6000,TRUE);
    }
   else
    {
     QString cmd=USB3GPATH;
     cmd+="usb_modeswitch";

     QString param1="-c";

     QString param2=USB3GPATH;
     param2+="usb_modeswitch.d/"; //19d2^%0026";

     QString  vIDFile=USB3GFILEINFO_VID;
     QString  pIDFile=USB3GFILEINFO_PID;

     QFile   vidFile(vIDFile);
     QFile   pidFile(pIDFile);


     if (!vidFile.open(IO_ReadOnly)){  
         QMessageBox::information(this,"File Open Fail","VIDFile open fail !");
         return;  
     	}  
     if (!pidFile.open(IO_ReadOnly)){  
         QMessageBox::information(this,"File Open Fail","PIDFile open fail !");
         return;  
     	}  
   
     QTextStream  vid(&vidFile);
     QTextStream  pid(&pidFile);

     QString strVid=vid.readLine();
     QString strPid=pid.readLine();

     vidFile.close();
     pidFile.close();

     param2=param2+strVid+"^%"+strPid;
     QString param3="-W";

     m_cmdDialup->addArgument(cmd);
     m_cmdDialup->addArgument(param1);
     m_cmdDialup->addArgument(param2);
     m_cmdDialup->addArgument(param3);
  
     m_cmdDialup->start();
        //QMessageBox::information(this,"not ad3812","not ad3812");
	m_timer->start(6000,TRUE);
	
  }
  //wait 6 sec for dialup call pppd  
  // m_timer->start(6000,TRUE);
   QTimer::singleShot( 20000, this, SLOT(setConnectState()));
  } 
  else if (obj == m_ctlMinimize){ 
  
      showMinimized();

     QWidget *parent=parentWidget();
     if(parent!=NULL)
     {
        parent->showMinimized();
     }

  }
}

void QConnectForm::readOutput()
{
    //QMessageBox::information( this, "WCDMA-AD3812","readOutput",0,0 );
    QString output;
   QProcess* obj = (QProcess*)sender(); 
   if(obj==m_cmdPrepare){
     while (m_cmdPrepare->canReadLineStdout()){
        QString f =  m_cmdPrepare->readLineStdout();
	m_ctlMessage->append(f);
      }
       }
   else if(obj==m_cmdDialup){
     while (m_cmdDialup->canReadLineStdout()){
        QString f =  m_cmdDialup->readLineStdout();
    	   m_ctlMessage->append(f);
          
       int nIndex=-1;
       QString findStr="DNS";
       nIndex=f.find(findStr,false);

       if(nIndex!=-1){
           QString tmpAddress= f.right(f.length()-nIndex);

           int tmpAdd=tmpAddress.find("address",false);

             if(tmpAdd!=-1)
              {
                 QString address_DNS =tmpAddress.right(tmpAddress.length()-tmpAdd); //address IP

             //    QMessageBox::information(this,"Address_DNS", address_DNS);

                 QString strDNS=address_DNS.right(address_DNS.length()-sizeof("address"));

                // QMessageBox::information(this,"DNS", strDNS);
                
                if(!strDNS.isEmpty())
                {

                  QString dnsFile=DNSFILE;
                  QFile file(dnsFile);

                 if (!file.open(IO_WriteOnly)) 
                   {  
                      QMessageBox::information(this,"DNS",dnsFile+"open fail !" );
                   
                   }
 
                   QTextStream out(&file);  
                   out <<"nameserver"<< "  "<<strDNS << endl;
                  file.close();

                  m_bConnect=true;
                  m_ctlConnect->setEnabled(true);
                  m_ctlConnect->setText("Disconnect");

                }

              }
         } 
      }
    
    }
    int n=m_ctlMessage->numLines();
     bool mark=FALSE;
     m_ctlMessage->setCursorPosition(n,0,mark);

}

void QConnectForm::timeOut()
{
  //QMessageBox::information(this," start dialup ", "start");
QFileInfo fiET127(ET127);
   if(fiET127.exists()&&m_nType==2)
    {
        SetConnectType(2,1);
        m_timer->start(6000,TRUE);

    }
 
   m_cmdDialup->clearArguments();
  
   QString dialcmd=USB3GPATH;
   dialcmd+="bin/pppd";

   QString dialParam1="call";

   
   QString   dialParam2;

   if(m_nType==0&&m_nChildType==0)
       dialParam2="wcdma";
   else if(m_nType==0&&m_nChildType==1)
       dialParam2="wcdma-ad3812";
   else  if(m_nType==1&&m_nChildType==0)
       dialParam2="cdma2000";
   else if(m_nType==2&&m_nChildType==0)
       dialParam2="tdscdma";
   else if(m_nType==2&&m_nChildType==1)
       dialParam2="tdscdma-et127";

 
   m_cmdDialup->addArgument(dialcmd);
   m_cmdDialup->addArgument(dialParam1);
   m_cmdDialup->addArgument(dialParam2);
 
   m_cmdDialup->start();

   m_timer->stop();
}

void QConnectForm::SetConnectType(int nType,int childType)
{
       if(nType<0||childType<0)
       {
         QMessageBox::information(this,"Net ERROR ", "Net type set error");
         return;
       }
       m_nType=nType;
       m_nChildType=childType;
}

void QConnectForm::setConnectState()
{
  if(!m_bConnect)
   {
    m_ctlConnect->setEnabled(true);
    m_ctlConnect->setText("Connect");

    m_ctlMessage->clear();
    m_ctlMessage->append("Connect fail,please check your usb 3G card,or choose correct 3G net type......");
    m_bConnect=false;

  }
}











