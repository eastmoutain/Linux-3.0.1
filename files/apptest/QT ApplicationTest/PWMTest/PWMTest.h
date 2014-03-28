
#if !defined (__MAIN_FORM_H__)
# define __MAIN_FORM_H__ 
#include "UI_PWMTest.h" 

class QPWMTest: public QUIForm

{ 
 Q_OBJECT 
 public: QPWMTest(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);
 virtual ~QPWMTest(); 

 private slots: 
   void buttonClicked();
   void setFreq(int pwmfreq);

 private: 

  int m_fd; 
};

#endif
