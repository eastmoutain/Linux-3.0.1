
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
#include <qlistview.h>
#include <qtimer.h>

#include "WiFiTest.h"


QMainForm::QMainForm(QWidget * parent, const char * name, WFlags f) : QBaseForm(parent, name, f)
{


      ::system("ifconfig eth0 down");
      ::system("ifconfig lo down");

       m_resultSignal="";
       m_strIP="";
       m_strGateway="";
       m_strFistDNS="";
       m_strSecondDNS="";

       m_nDNS=0;


    this->move((QApplication::desktop()->width() - width())/2,(QApplication::desktop()->height() -height())/2);

  //  m_btnScan->setDisabled(true);
    m_btnDisconnect->setDisabled(true);

    // signals and slots connections
    connect( m_ListView, SIGNAL(doubleClicked(QListViewItem*) ), this, SLOT(doubleClicked(QListViewItem*) ) );
    connect(m_btnScan,   SIGNAL(clicked()), this, SLOT(scan()));
    connect(m_btnDisconnect,SIGNAL(clicked()), this, SLOT(Disconnect())); 
//    connect(m_btnIPConf, SIGNAL(clicked()), this, SLOT(setIPInfo())); 
    connect(m_btnIPInfo, SIGNAL(clicked()), this, SLOT(lookupIPInfo()));
    connect(m_btnMinimize, SIGNAL(clicked()), this, SLOT(Minimize()));

    m_ListView->removeColumn(0);// remove default column of QListView
    
    m_ListView->addColumn(tr("Essid"));
    m_ListView->addColumn(tr("Signal"));
    m_ListView->addColumn(tr("State"));

   

    m_ListView->setColumnWidth(0,120);
    m_ListView->setColumnWidth(1,60);
    m_ListView->setColumnWidth(2,80);


    m_cmdScanning = new QProcess(this);
    connect(m_cmdScanning, SIGNAL(readyReadStdout()), this, SLOT(readScanningOutput()));

    m_cmdConnecting=new QProcess(this);
    connect(m_cmdConnecting, SIGNAL(readyReadStdout()), this, SLOT(readConnectOutput()));


    //scanning wifi net 
    QTimer::singleShot(200, this, SLOT(startScanningWiFiNet()));

}

QMainForm::~QMainForm() 
{ 
    if(m_cmdScanning->isRunning())
    {
      m_cmdScanning->tryTerminate();
      QTimer::singleShot( 1000, m_cmdScanning, SLOT( kill() ) );

    }
     if(m_cmdScanning!=NULL)
      delete m_cmdScanning;

     if(m_cmdConnecting->isRunning())
      {
       m_cmdConnecting->tryTerminate();
       QTimer::singleShot( 1000, m_cmdConnecting, SLOT( kill() ) );
      }

    // if(m_cmdConnecting!=NULL) //why appliation error ?
     // delete m_cmdScanning;

   ::system("ifconfig wlan0  down");
   ::system("killall  udhcpc ");

   ::system("ifconfig eth0 up");
   ::system("ifconfig lo up");
   ::system("/etc/init.d/ifconfig-eth0");

}


void QMainForm::startScanningWiFiNet()
{
     ::system("ifconfig wlan0  down");
     ::system("ifconfig wlan0  up");
    
    
    m_ListView->clear();
  
   m_cmdScanning->clearArguments();
   m_cmdScanning->addArgument("iwlist");
   m_cmdScanning->addArgument("scanning");
   m_cmdScanning->start();
}

void QMainForm::readScanningOutput()
{

     while (m_cmdScanning->canReadLineStdout()) 
     {
        QString lineInfo =  m_cmdScanning->readLineStdout();

      //  qWarning(lineInfo);
    
       
      
       QString keyEssidStr="ESSID:";
       QString keySignalStr="Quality";//=30/70
       
        int nIndexQu=lineInfo.find(keySignalStr);

        if(nIndexQu!=-1)
         {
           QString netEssid;

       //      QMessageBox::warning(0,"signal","lineInfo");
           qWarning("<<<<<<debug<<<<find Signal");

          int nLen=lineInfo.length();

     //   qWarning("nLen=%d,nIndexQu=%d",nLen,nIndexQu);
   
          int signalLen=nLen-nIndexQu;

          QString result=lineInfo.mid(nIndexQu,signalLen);//   Quality=34/70  Signal level=-76 dBm
    
      //    qWarning(result);  

          int indextemp=result.find(" ");
 
           if(indextemp!=-1)
           {
          
             QString resultSignal=result.left(indextemp); //Quality=34/70 
          
        //   qWarning(resultSignal);  

           resultSignal.remove(0,strlen("Quality=")); //34/70 
         
       //    qWarning(resultSignal);
          
             m_resultSignal=resultSignal;

           }
 
        }
       
       int nIndex=lineInfo.find(keyEssidStr);
       if(nIndex!=-1)//find essid 
        {
          QString netEssid;

      //    qWarning("find essid");

         int nLen=lineInfo.length();

     //    qWarning("nLen=%d,nIndex=%d",nLen,nIndex);
   
         int essidLen=nLen-nIndex;

         QString resultEssid=lineInfo.mid(nIndex,essidLen);// "ESSID:"TP-LINK_65775E"
        
       //  qWarning("<<<<<<<<< %s",(const char*)resultEssid);

          QString temp=resultEssid.remove(0,7);
         
          netEssid=temp.left(temp.length()-1);

         qWarning("<<<<debug<<<<<The last is  %s",(const char*)netEssid);

         QListViewItem *lvi=  new QListViewItem(m_ListView, netEssid,m_resultSignal);
 
         m_resultSignal="";

        }

     }

}





void QMainForm::doubleClicked(QListViewItem* item)
{

   QPasswordSet *wdg = new QPasswordSet(this );

    if (QPEApplication::execDialog(wdg) == QDialog::Accepted ) 
    {
	  
      QString password=wdg->m_strPassword;
      
     if(!password.isEmpty())//  password input
      {
          //set password
        
         QString setKey;
         setKey.sprintf("iwconfig wlan0  key %s",(const char*)password);
  
        ::system(setKey);

    //    QMessageBox::information(this,"set pasword",setKey);

      }
     
     //connect wifi net 

     QString strEssid=item->text(0);
     
  //    qWarning("Essid is %s",(const char *)strEssid);
   //   QMessageBox::information(this,"set essid", "Essid is %s",(const char *)strEssid);
    
     if(!strEssid.isEmpty())
      {
          
        QString essid;
        essid.sprintf("iwconfig wlan0 essid  %s",(const char *)strEssid);
        ::system(essid);


         QListViewItem * cur = (QListViewItem*)m_ListView->currentItem();
         cur->setText(2,"wait...");
     
      } 

   // ::system("killall  udhcpc ");
    // use udhcpc   to get ip ,submask,mac gateway dns 
    QTimer::singleShot(1000, this, SLOT(startDHCPClient()));
   
  
    }


    delete wdg;
}


void QMainForm::startDHCPClient()
{
     
     m_cmdConnecting->clearArguments();
     m_cmdConnecting->addArgument("udhcpc");
     m_cmdConnecting->addArgument("-b");
     m_cmdConnecting->addArgument("-i");
     m_cmdConnecting->addArgument("wlan0");
     m_cmdConnecting->start();

//   QMessageBox::information(this,"start dhcp","start dhcp");


}

void QMainForm::scan()
{

   Disconnect();
   startScanningWiFiNet();

}

void QMainForm::Disconnect()
{

  

   QListViewItem * cur = (QListViewItem*)m_ListView->currentItem();
   if(cur!=NULL)
   {
    
     if(cur->text(2)=="Connect")
     {

       ::system("ifconfig wlan0 down");
       cur->setText(2,"Disconnect");


     }


      m_strIP="";
      m_strGateway="";
      m_strFistDNS="";
      m_strSecondDNS="";

    }



}

void QMainForm:: lookupIPInfo()
{

     QIPShowSetDialog *wdg = new QIPShowSetDialog(this );
    
     wdg->m_strIP=m_strIP;
     wdg->m_strFistDNS=m_strFistDNS;
     wdg->m_strSecondDNS=m_strSecondDNS;

    if (QPEApplication::execDialog(wdg) == QDialog::Accepted ) 
    {
        

    }

    delete wdg;




}

void QMainForm:: Minimize()
{

  this->hide();

}



void QMainForm::readConnectOutput()
{
   
   while (m_cmdConnecting->canReadLineStdout()) 
     {
        QString lineInfo =  m_cmdConnecting->readLineStdout();
        int nResult=lineInfo.find("No lease");
     
       
        if(nResult == -1)
        {
                   
          int indexIP=lineInfo.find("Sending select for");
          if(indexIP!=-1)// find IP
          {
            qWarning(lineInfo);

           QString temp=lineInfo.remove(indexIP,strlen("Sending select for"));
           QString IP=temp.left(temp.length()-strlen("..."));

         //   qWarning(IP);

            m_strIP=IP;

          // QMessageBox::information(this,"IP",IP);
          }
      
       
          int indexDNS = lineInfo.find("adding dns");
          if(indexDNS!=-1)
          {
            
             QString tempDNS=lineInfo.remove(indexDNS,strlen("adding dns"));
         
             if(m_nDNS==0)//first DNS 
             {
              m_nDNS=1;
              
              m_strFistDNS=tempDNS;

            //  QMessageBox::information(this,"First DNS",m_strFistDNS);
             qWarning("first dns is %s",(const char*)m_strFistDNS);

             }
             else if(m_nDNS==1)// second DNS
             {
               m_strSecondDNS=tempDNS;

             //  QMessageBox::information(this,"Sencond DNS",m_strSecondDNS);
               qWarning("first dns is %s",(const char*)m_strSecondDNS);
               m_nDNS=0;
        
    

             }

             QListViewItem * cur = (QListViewItem*)m_ListView->currentItem();
             cur->setText(2,"Connect");
  
             m_btnDisconnect->setDisabled(false);
                     
           }

        }
        else  //  connect error
        {
           QMessageBox::information(this,"Connect error ","Please check passord or DHCP Server of route device  is working");

          //  qWarning("Please check passord or DHCP Server of route device  is working");
            QListViewItem * cur = (QListViewItem*)m_ListView->currentItem();
            cur->setText(2,"Disconnect");
         
        }
   
    
  
   }
    



}














