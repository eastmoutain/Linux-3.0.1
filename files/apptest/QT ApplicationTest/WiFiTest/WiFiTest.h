#if !defined (__MAIN_FORM_H__) 
# define __MAIN_FORM_H__ 

#include <qtopia/qprocess.h>

#include "passwordSet.h"
#include "UI_WiFiTest.h"
#include "IPShowSet.h"

 class QMainForm: public QBaseForm
 {
  Q_OBJECT 
  public:

   QMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);

   virtual ~QMainForm(); 

  private slots: 

   void  doubleClicked(QListViewItem* item);
   void scan();
   void Disconnect();
//   void setIPInfo();
   void lookupIPInfo();
   void Minimize();
   void readScanningOutput();
   void readConnectOutput();


   void  startScanningWiFiNet();
   void  startDHCPClient();

  private:
     QProcess*   m_cmdScanning;
     QString     m_resultSignal;
    
     QProcess*   m_cmdConnecting;

    QString     m_strIP;
    QString     m_strGateway;
    QString     m_strFistDNS;
    QString     m_strSecondDNS;


    unsigned int m_nDNS;
 
 
 
 }; 

#endif
