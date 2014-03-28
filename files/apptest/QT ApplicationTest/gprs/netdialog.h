#if !defined (__NET_DIALOG_H__)
# define __MAIN_FORM_H__

#include <qmultilineedit.h>
#include <qtopia/qprocess.h>
#include <qtimer.h>

#include "net_dialog.h"

#define PPPPATH           "/opt/3G/"

class NetDialog: public NetdialogForm
{
  Q_OBJECT
  public:

   NetDialog(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);

  // virtual ~NetDialog();

private:
	void readnetOutput();
	
private slots:

    void startbtnclicked();
    //void minibtnclicked();
	void readOutput();
	void stopbtnclicked();
private:
	QProcess* m_startgprs;
	QTimer *m_timer;


};

 #endif
