/****************************************************************************
** Form implementation generated from reading ui file 'comset_dialog.ui'
**
** Created: Tue Apr 10 00:32:00 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "comset_dialog.h"

#include <qcombobox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a COMForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
COMForm::COMForm( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "COMForm" );
    resize( 226, 260 ); 
    setMaximumSize( QSize( 230, 260 ) );
    setCaption( tr( "COMSet_dialog" ) );

    GroupBox5 = new QGroupBox( this, "GroupBox5" );
    GroupBox5->setGeometry( QRect( 11, -3, 200, 250 ) ); 
    GroupBox5->setFrameShape( QGroupBox::Box );
    GroupBox5->setFrameShadow( QGroupBox::Sunken );
    GroupBox5->setTitle( tr( "Setting" ) );

    TextLabel1_4 = new QLabel( GroupBox5, "TextLabel1_4" );
    TextLabel1_4->setGeometry( QRect( 13, 143, 71, 30 ) ); 
    TextLabel1_4->setText( tr( "Stopbits" ) );

    TextLabel1_5 = new QLabel( GroupBox5, "TextLabel1_5" );
    TextLabel1_5->setGeometry( QRect( 20, 183, 71, 30 ) ); 
    TextLabel1_5->setText( tr( "Parity" ) );

    TextLabel1_2 = new QLabel( GroupBox5, "TextLabel1_2" );
    TextLabel1_2->setGeometry( QRect( 20, 63, 71, 30 ) ); 
    TextLabel1_2->setText( tr( "Speed" ) );

    TextLabel1_3 = new QLabel( GroupBox5, "TextLabel1_3" );
    TextLabel1_3->setGeometry( QRect( 16, 103, 71, 30 ) ); 
    TextLabel1_3->setText( tr( "Databits" ) );

    TextLabel1 = new QLabel( GroupBox5, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 32, 23, 71, 30 ) ); 
    TextLabel1->setText( tr( "Port" ) );

    portNameComboBox = new QComboBox( FALSE, GroupBox5, "portNameComboBox" );
    portNameComboBox->insertItem( tr( "/dev/ttySAC0" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC1" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC2" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC3" ) );
    portNameComboBox->setGeometry( QRect( 82, 20, 101, 31 ) ); 

    dataBitsComboBox = new QComboBox( FALSE, GroupBox5, "dataBitsComboBox" );
    dataBitsComboBox->insertItem( tr( "8" ) );
    dataBitsComboBox->insertItem( tr( "7" ) );
    dataBitsComboBox->setGeometry( QRect( 83, 103, 101, 31 ) ); 

    parityComboBox = new QComboBox( FALSE, GroupBox5, "parityComboBox" );
    parityComboBox->insertItem( tr( "N" ) );
    parityComboBox->insertItem( tr( "O" ) );
    parityComboBox->insertItem( tr( "E" ) );
    parityComboBox->setGeometry( QRect( 83, 183, 101, 31 ) ); 

    stopBitsComboBox = new QComboBox( FALSE, GroupBox5, "stopBitsComboBox" );
    stopBitsComboBox->insertItem( tr( "1" ) );
    stopBitsComboBox->insertItem( tr( "2" ) );
    stopBitsComboBox->setGeometry( QRect( 83, 143, 101, 31 ) ); 

    speedComboBox = new QComboBox( FALSE, GroupBox5, "speedComboBox" );
    speedComboBox->insertItem( tr( "115200" ) );
    speedComboBox->insertItem( tr( "9600" ) );
    speedComboBox->insertItem( tr( "4800" ) );
    speedComboBox->setGeometry( QRect( 82, 60, 101, 31 ) ); 

    ok_Btn = new QPushButton( GroupBox5, "ok_Btn" );
    ok_Btn->setGeometry( QRect( 130, 216, 61, 31 ) ); 
    ok_Btn->setText( tr( "OK" ) );

    m_btnMinimize = new QPushButton( this, "m_btnMinimize" );
    m_btnMinimize->setGeometry( QRect( 46, 213, 60, 31 ) ); 
    m_btnMinimize->setText( tr( "mini" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
COMForm::~COMForm()
{
    // no need to delete child widgets, Qt does it all for us
}

