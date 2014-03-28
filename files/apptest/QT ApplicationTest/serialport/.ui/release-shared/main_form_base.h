/****************************************************************************
** Form interface generated from reading ui file 'main_form_base.ui'
**
** Created: Thu Apr 26 00:55:04 2012
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
class QGroupBox;
class QLabel;
class QMultiLineEdit;
class QPushButton;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QLabel* TextLabel2;
    QLabel* TextLabel2_2;
    QPushButton* closeMyComBtn;
    QPushButton* sendMsgBtn;
    QPushButton* openMyComBtn;
    QMultiLineEdit* m_receiveEdit;
    QMultiLineEdit* m_sendEdit;
    QGroupBox* GroupBox5;
    QLabel* TextLabel1_2;
    QLabel* TextLabel1_3;
    QLabel* TextLabel1_4;
    QLabel* TextLabel1_5;
    QComboBox* parityComboBox;
    QComboBox* dataBitsComboBox;
    QLabel* TextLabel1;
    QComboBox* speedComboBox;
    QComboBox* stopBitsComboBox;
    QComboBox* portNameComboBox;

public slots:
    virtual void sendButtonClicked();

protected:
    bool event( QEvent* );
};

#endif // TMAINFORMBASE_H
