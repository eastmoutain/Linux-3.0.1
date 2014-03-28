#if !defined (__MAIN_FORM_H__) 
# define __MAIN_FORM_H__ 


#include "UI_ledTest.h"

 class TMainForm: public TMainFormBase
 {
  Q_OBJECT 
  public:

   TMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);

   virtual ~TMainForm(); 

  private slots: 
   
    void checkBoxClicked();

  private: 
    int m_fd; 
 };

 #endif
