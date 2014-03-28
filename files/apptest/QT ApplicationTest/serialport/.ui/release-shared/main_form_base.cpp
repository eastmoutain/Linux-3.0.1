/****************************************************************************
** Form implementation generated from reading ui file 'main_form_base.ui'
**
** Created: Thu Apr 26 00:55:06 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "main_form_base.h"

#include <qcombobox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qmultilineedit.h>
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
    resize( 480, 239 ); 
    setMaximumSize( QSize( 480, 250 ) );
    setCaption( tr( "SerialPort Assistant" ) );

    TextLabel2 = new QLabel( this, "TextLabel2" );
    TextLabel2->setGeometry( QRect( 270, 0, 170, 31 ) ); 
    TextLabel2->setText( tr( "Received Message" ) );

    TextLabel2_2 = new QLabel( this, "TextLabel2_2" );
    TextLabel2_2->setGeometry( QRect( 270, 110, 170, 31 ) ); 
    TextLabel2_2->setText( tr( "Send Message" ) );

    closeMyComBtn = new QPushButton( this, "closeMyComBtn" );
    closeMyComBtn->setGeometry( QRect( 381, 197, 60, 30 ) ); 
    closeMyComBtn->setText( tr( "Close" ) );

    sendMsgBtn = new QPushButton( this, "sendMsgBtn" );
    sendMsgBtn->setGeometry( QRect( 311, 197, 60, 30 ) ); 
    sendMsgBtn->setText( tr( "Send" ) );

    openMyComBtn = new QPushButton( this, "openMyComBtn" );
    openMyComBtn->setGeometry( QRect( 241, 197, 60, 30 ) ); 
    openMyComBtn->setText( tr( "Open" ) );

    m_receiveEdit = new QMultiLineEdit( this, "m_receiveEdit" );
    m_receiveEdit->setGeometry( QRect( 220, 30, 240, 80 ) ); 

    m_sendEdit = new QMultiLineEdit( this, "m_sendEdit" );
    m_sendEdit->setGeometry( QRect( 220, 140, 240, 50 ) ); 

    GroupBox5 = new QGroupBox( this, "GroupBox5" );
    GroupBox5->setGeometry( QRect( 10, 0, 200, 241 ) ); 
    QFont GroupBox5_font(  GroupBox5->font() );
    GroupBox5_font.setPointSize( 8 );
    GroupBox5->setFont( GroupBox5_font ); 
    GroupBox5->setTitle( tr( "Setting" ) );

    TextLabel1_2 = new QLabel( GroupBox5, "TextLabel1_2" );
    TextLabel1_2->setGeometry( QRect( 20, 60, 71, 30 ) ); 
    TextLabel1_2->setText( tr( "Speed" ) );

    TextLabel1_3 = new QLabel( GroupBox5, "TextLabel1_3" );
    TextLabel1_3->setGeometry( QRect( 16, 99, 71, 30 ) ); 
    TextLabel1_3->setText( tr( "Databits" ) );

    TextLabel1_4 = new QLabel( GroupBox5, "TextLabel1_4" );
    TextLabel1_4->setGeometry( QRect( 13, 143, 71, 30 ) ); 
    TextLabel1_4->setText( tr( "Stopbits" ) );

    TextLabel1_5 = new QLabel( GroupBox5, "TextLabel1_5" );
    TextLabel1_5->setGeometry( QRect( 21, 180, 71, 30 ) ); 
    TextLabel1_5->setText( tr( "Parity" ) );

    parityComboBox = new QComboBox( FALSE, GroupBox5, "parityComboBox" );
    parityComboBox->insertItem( tr( "N" ) );
    parityComboBox->insertItem( tr( "O" ) );
    parityComboBox->insertItem( tr( "E" ) );
    parityComboBox->setGeometry( QRect( 83, 180, 101, 31 ) ); 
    QFont parityComboBox_font(  parityComboBox->font() );
    parityComboBox->setFont( parityComboBox_font ); 

    dataBitsComboBox = new QComboBox( FALSE, GroupBox5, "dataBitsComboBox" );
    dataBitsComboBox->insertItem( tr( "8" ) );
    dataBitsComboBox->insertItem( tr( "7" ) );
    dataBitsComboBox->setGeometry( QRect( 83, 101, 101, 31 ) ); 
    QFont dataBitsComboBox_font(  dataBitsComboBox->font() );
    dataBitsComboBox->setFont( dataBitsComboBox_font ); 

    TextLabel1 = new QLabel( GroupBox5, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 32, 23, 71, 30 ) ); 
    TextLabel1->setText( tr( "Port" ) );

    speedComboBox = new QComboBox( FALSE, GroupBox5, "speedComboBox" );
    speedComboBox->insertItem( tr( "115200" ) );
    speedComboBox->insertItem( tr( "9600" ) );
    speedComboBox->insertItem( tr( "4800" ) );
    speedComboBox->setGeometry( QRect( 83, 60, 101, 31 ) ); 
    QFont speedComboBox_font(  speedComboBox->font() );
    speedComboBox->setFont( speedComboBox_font ); 

    stopBitsComboBox = new QComboBox( FALSE, GroupBox5, "stopBitsComboBox" );
    stopBitsComboBox->insertItem( tr( "1" ) );
    stopBitsComboBox->insertItem( tr( "2" ) );
    stopBitsComboBox->setGeometry( QRect( 83, 143, 101, 31 ) ); 
    QFont stopBitsComboBox_font(  stopBitsComboBox->font() );
    stopBitsComboBox->setFont( stopBitsComboBox_font ); 

    portNameComboBox = new QComboBox( FALSE, GroupBox5, "portNameComboBox" );
    portNameComboBox->insertItem( tr( "/dev/ttySAC0" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC1" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC2" ) );
    portNameComboBox->insertItem( tr( "/dev/ttySAC3" ) );
    portNameComboBox->setGeometry( QRect( 83, 20, 100, 31 ) ); 
    QFont portNameComboBox_font(  portNameComboBox->font() );
    portNameComboBox->setFont( portNameComboBox_font ); 

    // signals and slots connections
    connect( sendMsgBtn, SIGNAL( clicked() ), this, SLOT( sendButtonClicked() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool TMainFormBase::event( QEvent* ev )
{
    bool ret = QWidget::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont GroupBox5_font(  GroupBox5->font() );
	GroupBox5_font.setPointSize( 8 );
	GroupBox5->setFont( GroupBox5_font ); 
	QFont parityComboBox_font(  parityComboBox->font() );
	parityComboBox->setFont( parityComboBox_font ); 
	QFont dataBitsComboBox_font(  dataBitsComboBox->font() );
	dataBitsComboBox->setFont( dataBitsComboBox_font ); 
	QFont speedComboBox_font(  speedComboBox->font() );
	speedComboBox->setFont( speedComboBox_font ); 
	QFont stopBitsComboBox_font(  stopBitsComboBox->font() );
	stopBitsComboBox->setFont( stopBitsComboBox_font ); 
	QFont portNameComboBox_font(  portNameComboBox->font() );
	portNameComboBox->setFont( portNameComboBox_font ); 
    }
    return ret;
}

void TMainFormBase::sendButtonClicked()
{
    qWarning( "TMainFormBase::sendButtonClicked(): Not implemented yet!" );
}

