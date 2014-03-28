/****************************************************************************
** Form interface generated from reading ui file 'net_dialog.ui'
**
** Created: Wed Apr 25 23:46:09 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef NETDIALOGFORM_H
#define NETDIALOGFORM_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QMultiLineEdit;
class QPushButton;

class NetdialogForm : public QDialog
{ 
    Q_OBJECT

public:
    NetdialogForm( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~NetdialogForm();

    QMultiLineEdit* gprsInfo_LineEdit;
    QPushButton* start_Btn;
    QPushButton* stop_Btn;

};

#endif // NETDIALOGFORM_H
