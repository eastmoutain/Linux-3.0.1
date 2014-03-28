
#if !defined (_KEY_TEST_H_2011_01_26) 
# define _KEY_TEST_H_2011_01_26

#include "UI_KeyTest.h" 

#define  KEYDEVICE  "/dev/input/event0" //forlinx 's  key device  is  /dev/event0, what about you?
#define  KEYMAXNUM  6

class QSocketNotifier; //need this class 
 
struct InputData 
{ 
    unsigned int dummy1; 
    unsigned int dummy2; 
    unsigned short type; 
    unsigned short code; 
    unsigned int value; 
    unsigned int dummy3; 
    unsigned int dummy4; 
    unsigned int dummy5; 
    unsigned int dummy6; 
};

#define KEY_UP			103   // key 1
#define KEY_DOWN		108   // key 2
#define KEY_LEFT		105   // key 3
#define KEY_RIGHT		106   // key 4
#define KEY_ENTER		28    // key 5
#define KEY_ESC			1     // key 6


class QKeyTestForm: public QKeyForm
{

Q_OBJECT
 
public:
 
  QKeyTestForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 

virtual 

 ~QKeyTestForm(); 

protected: 

  void paintEvent(QPaintEvent* e); 

private slots:

  void keyEvent();

private: 

  int m_fd;
  QSocketNotifier* m_notifyObject; 

  bool m_oldButtonsState[KEYMAXNUM]; 

};
#endif
