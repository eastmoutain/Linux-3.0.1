


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
#include <qsocketnotifier.h>
#include <qpainter.h> 

#include "keyTest.h"

QKeyTestForm::QKeyTestForm(QWidget * parent, const char * name, WFlags f):QKeyForm(parent, name, f) 
{ 
   
    m_fd = ::open(KEYDEVICE, O_RDONLY | O_NONBLOCK); 

   if (m_fd < 0) 
   { 
     QString openInfo;
 
     openInfo=openInfo.sprintf("Fail to open %s,Please check your key  device",KEYDEVICE);
     QMessageBox::information(this,"Error", openInfo);

     return; 
   }

   

   memset(m_oldButtonsState, 0, sizeof(m_oldButtonsState));

   m_notifyObject = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
  
   connect (m_notifyObject, SIGNAL(activated(int)), this, SLOT(keyEvent())); 

  // QMessageBox::information(this,"ConnectOK", "ConnectOK");
    
 } 


 QKeyTestForm::~QKeyTestForm() 
 {
    delete m_notifyObject; 
    ::close(m_fd); 

 } 

 void QKeyTestForm::keyEvent() 
 { 
   char buffer[KEYMAXNUM];
   memset(buffer, 0, sizeof(buffer));

   struct InputData  event; 

   int nResult=::read(m_fd, &event, sizeof(event));


   if (nResult !=  sizeof(InputData)) 
   {
        QMessageBox::information(this,"Debug","read error"); 
        return; 
    } 

   //QString debugInfo;
   //debugInfo=debugInfo.sprintf("key pressed: type=%d, code=0x%x, value=%d, %s\n", event.type, event.code, event.value, (event.value != 0)? "(Down)" : "(Up)");
   //QMessageBox::information(this,"Debug", debugInfo);
  
   switch(event.code)
   {
     case KEY_UP:
          {
            buffer[0]=event.value;
          }
          break;

     case KEY_DOWN:
          {
            buffer[1]=event.value;
          }
          break;
     case KEY_LEFT:
          {
            buffer[2]=event.value;
          }
          break;
     case KEY_RIGHT:
          { 
           buffer[3]=event.value;
          }
          break;
     case KEY_ENTER:
          {
          buffer[4]=event.value;
          }
         break;
     case KEY_ESC:
          {
           buffer[5]=event.value;
          }
         break;
    default:
         {
          break;
         }
   }


  for (unsigned i = 0; i < sizeof(buffer) / sizeof(buffer[0]); i++) 
   { 
     bool oldState = m_oldButtonsState[i]; 
     bool isOn = (buffer[i] & 0x01); 

     if (oldState != isOn)
     {
       m_oldButtonsState[i] = isOn;
     
      // QString debugInfo;
       //debugInfo=debugInfo.sprintf("Key %d  %s", i+1,isOn? "On" :"off");
      // QMessageBox::information(this,"Debug", debugInfo);

       update();  //this function will call paintEvent 
      } 
   }
 
 }

 void QKeyTestForm::paintEvent(QPaintEvent*) 
 {
   
   QPainter p(this); 
   int x = 40; 
   int y = 80; 
   const int w = 40; 
   const int h = 40; 
   const int space = 10;
 
   QString buttonText; 

   p.drawText(10,30,width(),height(),Qt::AlignCenter,"Waring:When you press key6 ,the application will exit !"); 

   for (int i = 0; i < KEYMAXNUM; i++) 
   { 
      if(i==0)
      {
        buttonText = buttonText.sprintf( "Up" );
      }else if(i==1)
      {
        buttonText = buttonText.sprintf( "Down" );
      }else if(i==2)
      {
        buttonText = buttonText.sprintf( "Left" );
      }else if(i==3)
      {
         buttonText = buttonText.sprintf( "Right" );
      }else if(i==4)
      {
         buttonText = buttonText.sprintf( "Enter" );
      }else if(i==5)
      {
         buttonText = buttonText.sprintf( "ESC" );
      }else
      {
         buttonText = buttonText.sprintf( "undefine key" );
      }
        
      
    if (m_oldButtonsState[i]) 
    { 
       p.fillRect(x,y,w,h,QBrush(QColor("#FF0000"))); 
       p.setPen( QColor("#FFFFFF") ); 
    }
    else 
    { 
      p.setPen( QColor("#000000") ); 
      p.drawRect(x,y,w,h); 
    } 
   
    p.drawText(x,y,w,h,Qt::AlignCenter,buttonText); 

    x += w + space; 

    if (x+w >= width()) 
    {
       x = 20; y += h + space;
    } 
   } 
}
















