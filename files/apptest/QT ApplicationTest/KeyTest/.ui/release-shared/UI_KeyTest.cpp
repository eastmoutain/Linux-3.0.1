/****************************************************************************
** Form implementation generated from reading ui file 'UI_KeyTest.ui'
**
** Created: Wed Jan 26 22:50:47 2011
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "UI_KeyTest.h"

#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QKeyForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
QKeyForm::QKeyForm( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "QKeyForm" );
    resize( 416, 272 ); 
    setMaximumSize( QSize( 420, 272 ) );
    setCaption( tr( "KeyTest" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QKeyForm::~QKeyForm()
{
    // no need to delete child widgets, Qt does it all for us
}

