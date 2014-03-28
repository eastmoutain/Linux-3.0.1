/****************************************************************************
** Form implementation generated from reading ui file 'mess_dialog.ui'
**
** Created: Wed Apr 25 22:47:41 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "mess_dialog.h"

#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QMesDialog which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QMesDialog::QMesDialog( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "QMesDialog" );
    resize( 240, 255 ); 
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, sizePolicy().hasHeightForWidth() ) );
    setMaximumSize( QSize( 240, 255 ) );
    setCaption( tr( "message_dialog" ) );

    mess_LineEdit = new QMultiLineEdit( this, "mess_LineEdit" );
    mess_LineEdit->setGeometry( QRect( 15, 10, 201, 170 ) ); 

    send_Btn = new QPushButton( this, "send_Btn" );
    send_Btn->setGeometry( QRect( 40, 190, 150, 40 ) ); 
    send_Btn->setText( tr( "send" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QMesDialog::~QMesDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

