
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

#include "3GTest.h"


QMainForm::QMainForm(QWidget * parent, const char * name, WFlags f) : QBaseForm(parent, name, f),
m_ConnectWCDMADialog(this),m_ConnectCDMA2000Dialog(this),m_ConnectTDSCDMADialog(this)
{
 // ::system("kill -s STOP `pidof 3GDialup`"); 
   ::system("ifconfig eth0 down");
   ::system("ifconfig lo down");
  // ::system("killall pppd");

  connect(m_ctlWCDMA,    SIGNAL(clicked()), this, SLOT(pushWCDMAlicked())); 
  connect(m_ctlCDMA2000, SIGNAL(clicked()), this, SLOT(pushCDMA2000licked())); 
  connect(m_ctlTDSCDMA,  SIGNAL(clicked()), this, SLOT(pushTDSCDMAlicked())); 

   QFileInfo fiVID(USB3GFILEINFO_VID  );
   QFileInfo fiPID(USB3GFILEINFO_PID);
    if ( !fiVID.exists() ||  !fiPID.exists())
    {
        QMessageBox::warning( 0, "Device not exist","USB 3G  Device not exist,Please input USB 3G Device !");
        ::system("killall 3GDialup"); 
    }

  //QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();
  //move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

   this->move((QApplication::desktop()->width() - width())/2,(QApplication::desktop()->height() -height())/2);


}

QMainForm::~QMainForm() 
{ 
   ::system("ifconfig eth0 up");
   ::system("ifconfig lo up");

}

void QMainForm:: pushWCDMAlicked()
{
    m_ConnectWCDMADialog.SetConnectType(0,0);
    //QMessageBox::information( this, "WCDMA","wcdma",0,0 );

    QPEApplication::execDialog(&m_ConnectWCDMADialog);
    return;

}
void QMainForm:: pushCDMA2000licked()
{
    m_ConnectCDMA2000Dialog.SetConnectType(1,0);
    QPEApplication::execDialog(&m_ConnectCDMA2000Dialog);

    return;
}
void  QMainForm::pushTDSCDMAlicked()
{
   m_ConnectTDSCDMADialog.SetConnectType(2,0);
   QPEApplication::execDialog(&m_ConnectTDSCDMADialog);
 
   return; 
}















