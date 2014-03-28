
#if !defined (_3G_CONNECT_2011_02_19) 
# define _3G_CONNECT_2011_02_19

#include "UI_Connect.h" 
#include <qtopia/qprocess.h>



#define USB3GFILEINFO_VID   "/sys/bus/usb/devices/1-1/idVendor" 
#define USB3GFILEINFO_PID   "/sys/bus/usb/devices/1-1/idProduct" 
#define USB3GPATH           "/opt/3G/"   //install path
#define DNSFILE             "/etc/resolv.conf"
#define ADFILE			   "/dev/ttyUSB3"
#define ET127               "/dev/ttyACM0"

class QConnectForm: public QDialup
{
Q_OBJECT
 
public:
  QConnectForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 

virtual ~QConnectForm(); 

void SetConnectType(int nType,int childType);

protected: 
 // void paintEvent(QPaintEvent* e);

private slots:

void runClicked();
void readOutput();
//void PreparelaunchFinished();
void timeOut();
void setConnectState();

private: 
  QProcess*   m_cmdPrepare;
  QProcess*   m_cmdDialup;
  QTimer *m_timer;

  bool m_bConnect;
  int m_nType; //0=3G   1=WIFI
  int m_nChildType;//0-0  wcdma  0-1 cdma2000  0-2 tdscdma 
};
#endif
