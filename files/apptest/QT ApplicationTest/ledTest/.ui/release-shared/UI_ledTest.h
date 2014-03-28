/****************************************************************************
** Form interface generated from reading ui file 'UI_ledTest.ui'
**
** Created: Mon Jan 24 19:39:36 2011
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef TMAINFORMBASE_H
#define TMAINFORMBASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QCheckBox;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QCheckBox* CheckBox4;
    QCheckBox* m_led1;
    QCheckBox* m_led4;
    QCheckBox* m_led3;
    QCheckBox* m_led2;

};

#endif // TMAINFORMBASE_H
