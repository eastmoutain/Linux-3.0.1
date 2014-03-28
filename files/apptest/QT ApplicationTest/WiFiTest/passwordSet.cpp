


#include <qlabel.h> 
#include <qpushbutton.h> 
#include <qlayout.h> 
#include <qspinbox.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/ioctl.h> 
#include <fcntl.h> 
#include <qapplication.h> 
#include <qmessagebox.h>
#include <qpainter.h> 
#include <qlineedit.h>

#include "passwordSet.h"

  
QPasswordSet::QPasswordSet(QWidget * parent, const char * name, WFlags f):QPasswordBase(parent, name, f) 
{   

 //   QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();
 //   move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

 //  this->move((QApplication::desktop()->width())/2,(QApplication::desktop()->height())/2);

   connect(m_btnConnect, SIGNAL(clicked()), this, SLOT(OK()));
   connect(m_btnCancel, SIGNAL(clicked()), this, SLOT(Cancel()));

   m_strPassword="";


}

QPasswordSet::~QPasswordSet() 
{






}

void QPasswordSet::OK()
{
   m_strPassword = m_editPassword->text();

   QDialog::accept();

}

void QPasswordSet::Cancel()
{

  QDialog::reject();


}














