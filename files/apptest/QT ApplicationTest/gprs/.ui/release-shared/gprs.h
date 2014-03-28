/****************************************************************************
** Form interface generated from reading ui file 'gprs.ui'
**
** Created: Mon Apr 2 07:49:09 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef TMAINFORM_H
#define TMAINFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLineEdit;
class QPushButton;

class TMainForm : public QWidget
{ 
    Q_OBJECT

public:
    TMainForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainForm();

    QPushButton* num5_Btn;
    QPushButton* num4_Btn;
    QPushButton* num2_Btn;
    QPushButton* num3_Btn;
    QPushButton* num1_Btn;
    QLineEdit* telnum_LineEdit;
    QPushButton* comset_Btn;
    QPushButton* mess_Btn;
    QPushButton* call_Btn;
    QPushButton* close_Btn;
    QPushButton* back_Btn;
    QPushButton* listen_Btn;
    QPushButton* num0_Btn;
    QPushButton* num7_Btn;
    QPushButton* num8_Btn;
    QPushButton* num9_Btn;
    QPushButton* num6_Btn;

};

#endif // TMAINFORM_H
