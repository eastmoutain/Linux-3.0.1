#if !defined (__MAIN_FORM_H__) 
# define __MAIN_FORM_H__ 
 
#include "main_form_base.h" 
#include <qsocketnotifier.h> 
#include <qcombobox.h>
class TMainForm: public TMainFormBase { 
     Q_OBJECT 
public: 
     TMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 
     virtual ~TMainForm(); 
 
private: 
     int openSerialPort(); 
 
private slots: 
     void sendButtonClicked(); 
     void remoteDataIncoming(); 
     void openMyCom();
	void closeMyCom();
private: 
     int m_fd; 
     QSocketNotifier *m_notifier; 
	QString portName;
 
}; 
 
#endif 
