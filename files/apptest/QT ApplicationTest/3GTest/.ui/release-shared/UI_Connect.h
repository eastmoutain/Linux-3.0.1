/****************************************************************************
** Form interface generated from reading ui file 'UI_Connect.ui'
**
** Created: Thu Mar 29 18:56:48 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QDIALUP_H
#define QDIALUP_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QMultiLineEdit;
class QPushButton;

class QDialup : public QDialog
{ 
    Q_OBJECT

public:
    QDialup( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QDialup();

    QPushButton* PushButton2;
    QPushButton* PushButton1;
    QMultiLineEdit* m_ctlMessage;
    QLabel* TextLabel1;
    QPushButton* m_ctlConnect;
    QPushButton* m_ctlMinimize;

};

#endif // QDIALUP_H
