/****************************************************************************
** Form interface generated from reading ui file 'mess_dialog.ui'
**
** Created: Wed Apr 25 22:47:38 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QMESDIALOG_H
#define QMESDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QMultiLineEdit;
class QPushButton;

class QMesDialog : public QDialog
{ 
    Q_OBJECT

public:
    QMesDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QMesDialog();

    QMultiLineEdit* mess_LineEdit;
    QPushButton* send_Btn;

};

#endif // QMESDIALOG_H
