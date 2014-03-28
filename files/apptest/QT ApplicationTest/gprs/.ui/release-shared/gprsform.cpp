/****************************************************************************
** Form implementation generated from reading ui file 'gprsform.ui'
**
** Created: Thu May 3 20:15:11 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gprsform.h"

#include <qcombobox.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
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
    resize( 472, 255 ); 
    setMaximumSize( QSize( 480, 255 ) );
    setCaption( tr( "Forlinx-GPRS" ) );

    GroupBox5 = new QGroupBox( this, "GroupBox5" );
    GroupBox5->setGeometry( QRect( 12, 2, 200, 250 ) ); 
    GroupBox5->setFrameShape( QGroupBox::Box );
    GroupBox5->setFrameShadow( QGroupBox::Sunken );
    GroupBox5->setTitle( tr( "Setting" ) );

    TextLabel1 = new QLabel( GroupBox5, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 32, 23, 71, 30 ) ); 
    TextLabel1->setText( tr( "Port" ) );

    portNameComboBox = new QComboBox( FALSE, GroupBox5, "portNameComboBox" );
    portNameComboBox->insertItem( tr( "/dev/ttySAC0" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC1" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC2" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC3" ) );
    portNameComboBox->setGeometry( QRect( 82, 20, 101, 31 ) ); 

    TextLabel1_2 = new QLabel( GroupBox5, "TextLabel1_2" );
    TextLabel1_2->setGeometry( QRect( 18, 53, 71, 30 ) ); 
    TextLabel1_2->setText( tr( "Speed" ) );

    speedComboBox = new QComboBox( FALSE, GroupBox5, "speedComboBox" );
    speedComboBox->insertItem( tr( "115200" ) );
    speedComboBox->insertItem( tr( "9600" ) );
    speedComboBox->insertItem( tr( "4800" ) );
    speedComboBox->setGeometry( QRect( 82, 54, 101, 31 ) ); 

    TextLabel1_3 = new QLabel( GroupBox5, "TextLabel1_3" );
    TextLabel1_3->setGeometry( QRect( 13, 87, 71, 30 ) ); 
    TextLabel1_3->setText( tr( "Databits" ) );

    dataBitsComboBox = new QComboBox( FALSE, GroupBox5, "dataBitsComboBox" );
    dataBitsComboBox->insertItem( tr( "8" ) );
    dataBitsComboBox->insertItem( tr( "7" ) );
    dataBitsComboBox->setGeometry( QRect( 83, 88, 101, 31 ) ); 

    TextLabel1_4 = new QLabel( GroupBox5, "TextLabel1_4" );
    TextLabel1_4->setGeometry( QRect( 11, 120, 71, 30 ) ); 
    TextLabel1_4->setText( tr( "Stopbits" ) );

    stopBitsComboBox = new QComboBox( FALSE, GroupBox5, "stopBitsComboBox" );
    stopBitsComboBox->insertItem( tr( "1" ) );
    stopBitsComboBox->insertItem( tr( "2" ) );
    stopBitsComboBox->setGeometry( QRect( 83, 122, 101, 31 ) ); 

    TextLabel1_5 = new QLabel( GroupBox5, "TextLabel1_5" );
    TextLabel1_5->setGeometry( QRect( 26, 156, 71, 30 ) ); 
    TextLabel1_5->setText( tr( "Parity" ) );

    parityComboBox = new QComboBox( FALSE, GroupBox5, "parityComboBox" );
    parityComboBox->insertItem( tr( "N" ) );
    parityComboBox->insertItem( tr( "O" ) );
    parityComboBox->insertItem( tr( "E" ) );
    parityComboBox->setGeometry( QRect( 83, 156, 101, 31 ) ); 

    ok_Btn = new QPushButton( GroupBox5, "ok_Btn" );
    ok_Btn->setGeometry( QRect( 125, 192, 61, 31 ) ); 
    ok_Btn->setText( tr( "OK" ) );

    Frame10 = new QFrame( this, "Frame10" );
    Frame10->setGeometry( QRect( 220, 0, 211, 251 ) ); 
    Frame10->setFrameShape( QFrame::StyledPanel );
    Frame10->setFrameShadow( QFrame::Raised );

    back_Btn = new QPushButton( Frame10, "back_Btn" );
    back_Btn->setGeometry( QRect( 75, 136, 60, 30 ) ); 
    back_Btn->setText( tr( "back" ) );

    net_Btn = new QPushButton( Frame10, "net_Btn" );
    net_Btn->setGeometry( QRect( 135, 136, 60, 30 ) ); 
    net_Btn->setText( tr( "gprs" ) );

    telnum_LineEdit = new QLineEdit( Frame10, "telnum_LineEdit" );
    telnum_LineEdit->setGeometry( QRect( 20, 10, 170, 31 ) ); 

    mini_Btn = new QPushButton( Frame10, "mini_Btn" );
    mini_Btn->setGeometry( QRect( 135, 196, 60, 30 ) ); 
    mini_Btn->setText( tr( "mini" ) );

    num1_Btn = new QPushButton( Frame10, "num1_Btn" );
    num1_Btn->setGeometry( QRect( 15, 46, 60, 30 ) ); 
    num1_Btn->setText( tr( "1" ) );

    num2_Btn = new QPushButton( Frame10, "num2_Btn" );
    num2_Btn->setGeometry( QRect( 75, 46, 60, 30 ) ); 
    num2_Btn->setText( tr( "2" ) );

    num3_Btn = new QPushButton( Frame10, "num3_Btn" );
    num3_Btn->setGeometry( QRect( 135, 46, 60, 30 ) ); 
    num3_Btn->setText( tr( "3" ) );

    num4_Btn = new QPushButton( Frame10, "num4_Btn" );
    num4_Btn->setGeometry( QRect( 15, 76, 60, 30 ) ); 
    num4_Btn->setText( tr( "4" ) );

    num5_Btn = new QPushButton( Frame10, "num5_Btn" );
    num5_Btn->setGeometry( QRect( 75, 76, 60, 30 ) ); 
    num5_Btn->setText( tr( "5" ) );

    num6_Btn = new QPushButton( Frame10, "num6_Btn" );
    num6_Btn->setGeometry( QRect( 135, 76, 60, 30 ) ); 
    num6_Btn->setText( tr( "6" ) );

    num7_Btn = new QPushButton( Frame10, "num7_Btn" );
    num7_Btn->setGeometry( QRect( 15, 106, 60, 30 ) ); 
    num7_Btn->setText( tr( "7" ) );

    num8_Btn = new QPushButton( Frame10, "num8_Btn" );
    num8_Btn->setGeometry( QRect( 75, 106, 60, 30 ) ); 
    num8_Btn->setText( tr( "8" ) );

    num9_Btn = new QPushButton( Frame10, "num9_Btn" );
    num9_Btn->setGeometry( QRect( 135, 106, 60, 30 ) ); 
    num9_Btn->setText( tr( "9" ) );

    num0_Btn = new QPushButton( Frame10, "num0_Btn" );
    num0_Btn->setGeometry( QRect( 15, 136, 60, 30 ) ); 
    num0_Btn->setText( tr( "0" ) );

    call_Btn = new QPushButton( Frame10, "call_Btn" );
    call_Btn->setEnabled( FALSE );
    call_Btn->setGeometry( QRect( 15, 166, 60, 30 ) ); 
    call_Btn->setText( tr( "call" ) );

    mess_Btn = new QPushButton( Frame10, "mess_Btn" );
    mess_Btn->setEnabled( FALSE );
    mess_Btn->setGeometry( QRect( 15, 196, 60, 30 ) ); 
    mess_Btn->setText( tr( "S-mes" ) );

    allmess_Btn = new QPushButton( Frame10, "allmess_Btn" );
    allmess_Btn->setEnabled( FALSE );
    allmess_Btn->setGeometry( QRect( 75, 196, 60, 30 ) ); 
    allmess_Btn->setText( tr( "A-mes" ) );

    listen_Btn = new QPushButton( Frame10, "listen_Btn" );
    listen_Btn->setEnabled( FALSE );
    listen_Btn->setGeometry( QRect( 75, 166, 60, 30 ) ); 
    listen_Btn->setText( tr( "listen" ) );

    stop_Btn = new QPushButton( Frame10, "stop_Btn" );
    stop_Btn->setEnabled( FALSE );
    stop_Btn->setGeometry( QRect( 135, 166, 60, 30 ) ); 
    stop_Btn->setText( tr( "stop" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

