/****************************************************************************
** Form interface generated from reading ui file 'scanmes_dialog.ui'
**
** Created: Mon Apr 23 20:20:51 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef SCANMESSFORM_H
#define SCANMESSFORM_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QListView;
class QListViewItem;
class QPushButton;

class ScanMessForm : public QDialog
{ 
    Q_OBJECT

public:
    ScanMessForm( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ScanMessForm();

    QLabel* PixmapLabel1;
    QPushButton* scan_btn;
    QListView* m_ListView;

};

#endif // SCANMESSFORM_H
