/****************************************************************************
** Form implementation generated from reading ui file 'UI_ledTest.ui'
**
** Created: Mon Jan 24 19:39:38 2011
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "UI_ledTest.h"

#include <qcheckbox.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a TMainFormBase which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
TMainFormBase::TMainFormBase( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TMainFormBase" );
    resize( 420, 271 ); 
    setMaximumSize( QSize( 420, 272 ) );
    setCaption( tr( "Form1" ) );

    CheckBox4 = new QCheckBox( this, "CheckBox4" );
    CheckBox4->setGeometry( QRect( 230, 280, 134, 29 ) ); 
    CheckBox4->setText( tr( "CheckBox4" ) );

    m_led1 = new QCheckBox( this, "m_led1" );
    m_led1->setGeometry( QRect( 200, 30, 134, 29 ) ); 
    m_led1->setText( tr( "Led1" ) );

    m_led4 = new QCheckBox( this, "m_led4" );
    m_led4->setGeometry( QRect( 200, 190, 134, 29 ) ); 
    m_led4->setText( tr( "Led4" ) );

    m_led3 = new QCheckBox( this, "m_led3" );
    m_led3->setGeometry( QRect( 200, 140, 134, 29 ) ); 
    m_led3->setText( tr( "Led3" ) );

    m_led2 = new QCheckBox( this, "m_led2" );
    m_led2->setGeometry( QRect( 200, 80, 134, 29 ) ); 
    m_led2->setText( tr( "Led2" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

