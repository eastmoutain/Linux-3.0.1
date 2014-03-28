
#include "PWMTest.h"
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
#include <qspinbox.h> 
#include <qstring.h>
#include <qmessagebox.h>
#include <qslider.h> 

#define PWM_IOCTL_SET_FREQ 1 
#define PWM_IOCTL_STOP 0 

QPWMTest::QPWMTest(QWidget * parent, const char * name, WFlags f) : QUIForm(parent, name, f) 
{ 

  m_fd = ::open("/dev/pwm", O_RDONLY); 
  ::ioctl(m_fd, PWM_IOCTL_STOP); 

 connect(m_startBuzzer, SIGNAL(clicked()), this, SLOT(buttonClicked()) ); 
 connect(m_stopBuzzer, SIGNAL(clicked()), this, SLOT(buttonClicked()) ); 
 connect(Freq_SpinBox,SIGNAL(valueChanged(int)),this,SLOT(setFreq(int)));
 Freq_SpinBox->setEnabled(false);
 Freq_Slider->setEnabled(false);
} 

QPWMTest::~QPWMTest() 
{ 
 ::ioctl(m_fd, PWM_IOCTL_STOP); 
 ::close(m_fd); 

}

void QPWMTest::setFreq(int pwmfreq)
{
 ::ioctl(m_fd, PWM_IOCTL_SET_FREQ, pwmfreq);
}

void QPWMTest::buttonClicked() 
{ 

 QPushButton* obj = (QPushButton*)sender(); 
 if (obj == m_startBuzzer) 
 {
  Freq_SpinBox->setEnabled(true);
  Freq_Slider->setEnabled(true);
  ::ioctl(m_fd, PWM_IOCTL_SET_FREQ, 1000); 
 
 } else if (obj == m_stopBuzzer) 
 { 
   ::ioctl(m_fd, PWM_IOCTL_STOP); 
   Freq_SpinBox->setEnabled(false);
   Freq_Slider->setEnabled(false);
 }
 
}















