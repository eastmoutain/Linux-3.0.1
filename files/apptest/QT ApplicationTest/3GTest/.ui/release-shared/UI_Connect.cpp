/****************************************************************************
** Form implementation generated from reading ui file 'UI_Connect.ui'
**
** Created: Thu Mar 29 18:56:53 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "UI_Connect.h"

#include <qlabel.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QDialup which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QDialup::QDialup( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "QDialup" );
    resize( 388, 272 ); 
    setMaximumSize( QSize( 480, 272 ) );
    setCaption( tr( "Diaup" ) );

    PushButton2 = new QPushButton( this, "PushButton2" );
    PushButton2->setGeometry( QRect( 110, 270, 171, 44 ) ); 
    PushButton2->setText( tr( "PushButton2" ) );

    PushButton1 = new QPushButton( this, "PushButton1" );
    PushButton1->setGeometry( QRect( 360, 270, 171, 44 ) ); 
    PushButton1->setText( tr( "PushButton1" ) );

    m_ctlMessage = new QMultiLineEdit( this, "m_ctlMessage" );
    m_ctlMessage->setGeometry( QRect( 20, 40, 210, 180 ) ); 
    m_ctlMessage->setText( tr( "" ) );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 30, 10, 150, 25 ) ); 
    TextLabel1->setText( tr( "Connect State:" ) );

    m_ctlConnect = new QPushButton( this, "m_ctlConnect" );
    m_ctlConnect->setGeometry( QRect( 240, 70, 130, 44 ) ); 
    m_ctlConnect->setText( tr( "Connect Net" ) );

    m_ctlMinimize = new QPushButton( this, "m_ctlMinimize" );
    m_ctlMinimize->setGeometry( QRect( 240, 140, 130, 44 ) ); 
    m_ctlMinimize->setText( tr( "Minimize" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QDialup::~QDialup()
{
    // no need to delete child widgets, Qt does it all for us
}

