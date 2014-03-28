/****************************************************************************
** Form implementation generated from reading ui file 'net_dialog.ui'
**
** Created: Wed Apr 25 23:46:12 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "net_dialog.h"

#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a NetdialogForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
NetdialogForm::NetdialogForm( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "NetdialogForm" );
    resize( 236, 255 ); 
    setMaximumSize( QSize( 240, 255 ) );
    setCaption( tr( "GPRS_Form" ) );

    gprsInfo_LineEdit = new QMultiLineEdit( this, "gprsInfo_LineEdit" );
    gprsInfo_LineEdit->setGeometry( QRect( 5, 10, 221, 190 ) ); 

    start_Btn = new QPushButton( this, "start_Btn" );
    start_Btn->setGeometry( QRect( 10, 200, 110, 31 ) ); 
    start_Btn->setText( tr( "connect" ) );

    stop_Btn = new QPushButton( this, "stop_Btn" );
    stop_Btn->setGeometry( QRect( 120, 200, 100, 31 ) ); 
    stop_Btn->setText( tr( "disconnect" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
NetdialogForm::~NetdialogForm()
{
    // no need to delete child widgets, Qt does it all for us
}

