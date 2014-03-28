
#if !defined (__PASSWORDSET_H_2011_03_08)

# define _PASSWORDSET_H_2011_03_08

#include "UI_Password.h" 
#include <qtopia/qprocess.h>

class QPasswordSet: public QPasswordBase
{
Q_OBJECT
 
public:
  QPasswordSet(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 

virtual ~QPasswordSet(); 



protected: 
 // void paintEvent(QPaintEvent* e);

private slots:
  void  OK();
  void  Cancel();


public:
 
 QString  m_strPassword ; 

};
#endif
