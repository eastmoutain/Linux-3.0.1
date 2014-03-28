#if !defined (__MAIN_FORM_H__) 
# define __MAIN_FORM_H__ 


#include "UI_3GTest.h"
#include "connect.h"

 class QMainForm: public QBaseForm
 {
  Q_OBJECT 
  public:

   QMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);

   virtual ~QMainForm(); 

  private slots: 
   
    void pushWCDMAlicked();
    void pushCDMA2000licked();
    void pushTDSCDMAlicked();

  private:
    QConnectForm  m_ConnectWCDMADialog;
    QConnectForm  m_ConnectCDMA2000Dialog;
    QConnectForm  m_ConnectTDSCDMADialog;
 }; 

 #endif
