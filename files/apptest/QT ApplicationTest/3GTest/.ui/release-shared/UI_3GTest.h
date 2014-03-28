/****************************************************************************
** Form interface generated from reading ui file 'UI_3GTest.ui'
**
** Created: Thu Mar 29 18:56:48 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QBASEFORM_H
#define QBASEFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QPushButton;

class QBaseForm : public QWidget
{ 
    Q_OBJECT

public:
    QBaseForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QBaseForm();

    QPushButton* m_ctlWCDMA;
    QLabel* PixmapLabel1;
    QLabel* PixmapLabel2;
    QPushButton* m_ctlCDMA2000;
    QLabel* PixmapLabel3;
    QPushButton* m_ctlTDSCDMA;
    QLabel* TextLabel1;

};

#endif // QBASEFORM_H
