
#if !defined (_IP_SHOW_2011_03_07) 
# define _IP_SHOW_2011_03_07

#include "UI_IPShowSet.h" 
#include <qtopia/qprocess.h>

class QIPShowSetDialog: public QIPBaseForm
{
Q_OBJECT
 
public:
  QIPShowSetDialog(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 

virtual ~QIPShowSetDialog(); 

protected: 
 // void paintEvent(QPaintEvent* e);

private slots:


 void readRouteOutput();
 void startGetway();
 void  OK();


private: 
  QProcess*   m_cmdGateway;

public:

    QString     m_strIP;
    QString     m_strGateway;
    QString     m_strFistDNS;
    QString     m_strSecondDNS;


};
#endif
