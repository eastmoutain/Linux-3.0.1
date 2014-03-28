/****************************************************************************
** Form interface generated from reading ui file 'gprsform.ui'
**
** Created: Thu May 3 20:15:08 2012
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
class QComboBox;
class QFrame;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QGroupBox* GroupBox5;
    QLabel* TextLabel1;
    QComboBox* portNameComboBox;
    QLabel* TextLabel1_2;
    QComboBox* speedComboBox;
    QLabel* TextLabel1_3;
    QComboBox* dataBitsComboBox;
    QLabel* TextLabel1_4;
    QComboBox* stopBitsComboBox;
    QLabel* TextLabel1_5;
    QComboBox* parityComboBox;
    QPushButton* ok_Btn;
    QFrame* Frame10;
    QPushButton* back_Btn;
    QPushButton* net_Btn;
    QLineEdit* telnum_LineEdit;
    QPushButton* mini_Btn;
    QPushButton* num1_Btn;
    QPushButton* num2_Btn;
    QPushButton* num3_Btn;
    QPushButton* num4_Btn;
    QPushButton* num5_Btn;
    QPushButton* num6_Btn;
    QPushButton* num7_Btn;
    QPushButton* num8_Btn;
    QPushButton* num9_Btn;
    QPushButton* num0_Btn;
    QPushButton* call_Btn;
    QPushButton* mess_Btn;
    QPushButton* allmess_Btn;
    QPushButton* listen_Btn;
    QPushButton* stop_Btn;

};

#endif // TMAINFORMBASE_H
