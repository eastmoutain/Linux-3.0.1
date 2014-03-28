#if !defined (__MAIN_FORM_H__)
# define __MAIN_FORM_H__

#include <qlineedit.h>
#include "gprsform.h"
#include "messdialog.h"
#include "netdialog.h"
#include "scanmes.h"
#include <qsocketnotifier.h>



class TMainForm: public TMainFormBase
{
  Q_OBJECT
  public:

   TMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);

   virtual ~TMainForm();



private:
     int openSerialPort();
	
private slots:

    void numbtnclicked();
    void allmessbtnclicked();
    void listenbtnclicked();
    void backbtnclicked();
    void callbtnclcked();
    void messbtnclicked();
    void netbtnclicked();
    void remoteDataIncoming();
    void openMyCom();
	void stopbtnclicked();
	void minibtnclicked();
    

private:
	QString telnum;
	QSocketNotifier *m_notifier;
	QString portName;
	
};

 #endif
