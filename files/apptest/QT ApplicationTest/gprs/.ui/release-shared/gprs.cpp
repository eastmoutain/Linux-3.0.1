/****************************************************************************
** Form implementation generated from reading ui file 'gprs.ui'
**
** Created: Mon Apr 2 07:49:09 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gprs.h"

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a TMainForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
TMainForm::TMainForm( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TMainForm" );
    resize( 226, 260 ); 
    setMaximumSize( QSize( 230, 260 ) );
    setCaption( tr( "Forlinx-GPRS" ) );

    num5_Btn = new QPushButton( this, "num5_Btn" );
    num5_Btn->setGeometry( QRect( 80, 105, 60, 30 ) ); 
    num5_Btn->setText( tr( "5" ) );

    num4_Btn = new QPushButton( this, "num4_Btn" );
    num4_Btn->setGeometry( QRect( 20, 105, 60, 30 ) ); 
    num4_Btn->setText( tr( "4" ) );

    num2_Btn = new QPushButton( this, "num2_Btn" );
    num2_Btn->setGeometry( QRect( 80, 76, 60, 30 ) ); 
    num2_Btn->setText( tr( "2" ) );

    num3_Btn = new QPushButton( this, "num3_Btn" );
    num3_Btn->setGeometry( QRect( 140, 76, 60, 30 ) ); 
    num3_Btn->setText( tr( "3" ) );

    num1_Btn = new QPushButton( this, "num1_Btn" );
    num1_Btn->setGeometry( QRect( 20, 76, 60, 30 ) ); 
    num1_Btn->setText( tr( "1" ) );

    telnum_LineEdit = new QLineEdit( this, "telnum_LineEdit" );
    telnum_LineEdit->setGeometry( QRect( 24, 41, 170, 31 ) ); 

    comset_Btn = new QPushButton( this, "comset_Btn" );
    comset_Btn->setGeometry( QRect( 20, 10, 180, 30 ) ); 
    comset_Btn->setText( tr( "COM set" ) );

    mess_Btn = new QPushButton( this, "mess_Btn" );
    mess_Btn->setGeometry( QRect( 80, 196, 60, 30 ) ); 
    mess_Btn->setText( tr( "mess" ) );

    call_Btn = new QPushButton( this, "call_Btn" );
    call_Btn->setGeometry( QRect( 20, 196, 60, 30 ) ); 
    call_Btn->setText( tr( "call" ) );

    close_Btn = new QPushButton( this, "close_Btn" );
    close_Btn->setGeometry( QRect( 140, 196, 60, 30 ) ); 
    close_Btn->setText( tr( "close" ) );

    back_Btn = new QPushButton( this, "back_Btn" );
    back_Btn->setGeometry( QRect( 140, 165, 60, 30 ) ); 
    back_Btn->setText( tr( "back" ) );

    listen_Btn = new QPushButton( this, "listen_Btn" );
    listen_Btn->setGeometry( QRect( 20, 165, 60, 30 ) ); 
    listen_Btn->setText( tr( "listen" ) );

    num0_Btn = new QPushButton( this, "num0_Btn" );
    num0_Btn->setGeometry( QRect( 80, 165, 60, 30 ) ); 
    num0_Btn->setText( tr( "0" ) );

    num7_Btn = new QPushButton( this, "num7_Btn" );
    num7_Btn->setGeometry( QRect( 20, 135, 60, 30 ) ); 
    num7_Btn->setText( tr( "7" ) );

    num8_Btn = new QPushButton( this, "num8_Btn" );
    num8_Btn->setGeometry( QRect( 80, 135, 60, 30 ) ); 
    num8_Btn->setText( tr( "8" ) );

    num9_Btn = new QPushButton( this, "num9_Btn" );
    num9_Btn->setGeometry( QRect( 140, 135, 60, 30 ) ); 
    num9_Btn->setText( tr( "9" ) );

    num6_Btn = new QPushButton( this, "num6_Btn" );
    num6_Btn->setGeometry( QRect( 140, 105, 60, 30 ) ); 
    num6_Btn->setText( tr( "6" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainForm::~TMainForm()
{
    // no need to delete child widgets, Qt does it all for us
}

