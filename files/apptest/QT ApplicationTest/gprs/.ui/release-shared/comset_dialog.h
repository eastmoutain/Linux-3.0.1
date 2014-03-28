/****************************************************************************
** Form interface generated from reading ui file 'comset_dialog.ui'
**
** Created: Tue Apr 10 00:31:45 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef COMFORM_H
#define COMFORM_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QComboBox;
class QGroupBox;
class QLabel;
class QPushButton;

class COMForm : public QDialog
{ 
    Q_OBJECT

public:
    COMForm( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~COMForm();

    QGroupBox* GroupBox5;
    QLabel* TextLabel1_4;
    QLabel* TextLabel1_5;
    QLabel* TextLabel1_2;
    QLabel* TextLabel1_3;
    QLabel* TextLabel1;
    QComboBox* portNameComboBox;
    QComboBox* dataBitsComboBox;
    QComboBox* parityComboBox;
    QComboBox* stopBitsComboBox;
    QComboBox* speedComboBox;
    QPushButton* ok_Btn;
    QPushButton* m_btnMinimize;

};

#endif // COMFORM_H
