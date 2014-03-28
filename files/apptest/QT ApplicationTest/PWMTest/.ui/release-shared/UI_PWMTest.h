/****************************************************************************
** Form interface generated from reading ui file 'UI_PWMTest.ui'
**
** Created: Tue Apr 24 20:57:40 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QUIFORM_H
#define QUIFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QPushButton;
class QSlider;
class QSpinBox;

class QUIForm : public QWidget
{ 
    Q_OBJECT

public:
    QUIForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QUIForm();

    QPushButton* m_startBuzzer;
    QPushButton* m_stopBuzzer;
    QSpinBox* Freq_SpinBox;
    QSlider* Freq_Slider;
    QLabel* TextLabel1;

public slots:
    virtual void setFreq();

};

#endif // QUIFORM_H
