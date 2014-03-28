
#include <qcheckbox.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/ioctl.h> 
#include <fcntl.h>
#include <ledtest.h>

TMainForm::TMainForm(QWidget * parent, const char * name, WFlags f) : TMainFormBase(parent, name, f) 
{
  ::system("kill -s STOP `pidof led-player`"); 

  m_fd = ::open("/dev/leds0", O_RDONLY); 

   if (m_fd < 0) 
   { 
 
     m_fd = ::open("/dev/leds", O_RDONLY); 

   } 
 
 connect(m_led1, SIGNAL(clicked()), this, SLOT(checkBoxClicked()) ); 
 connect(m_led2, SIGNAL(clicked()), this, SLOT(checkBoxClicked()) ); 
 connect(m_led3, SIGNAL(clicked()), this, SLOT(checkBoxClicked()) ); 
 connect(m_led4, SIGNAL(clicked()), this, SLOT(checkBoxClicked()) );

 checkBoxClicked(); 

 }

 TMainForm::~TMainForm() 
 { 
  ::close(m_fd);
 }

void TMainForm::checkBoxClicked() 
{ 
  ioctl(m_fd, int(m_led1->isChecked()), 0);
  ioctl(m_fd, int(m_led2->isChecked()), 1); 
  ioctl(m_fd, int(m_led3->isChecked()), 2); 
  ioctl(m_fd, int(m_led4->isChecked()), 3); 

}
