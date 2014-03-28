/****************************************************************************
** Form implementation generated from reading ui file 'UI_PWMTest.ui'
**
** Created: Tue Apr 24 20:57:41 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "UI_PWMTest.h"

#include <qlabel.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QUIForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
QUIForm::QUIForm( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "QUIForm" );
    resize( 416, 234 ); 
    setMaximumSize( QSize( 420, 272 ) );
    setCaption( tr( "PWMTest" ) );

    m_startBuzzer = new QPushButton( this, "m_startBuzzer" );
    m_startBuzzer->setGeometry( QRect( 20, 50, 171, 44 ) ); 
    m_startBuzzer->setText( tr( "StartBuzzer  " ) );

    m_stopBuzzer = new QPushButton( this, "m_stopBuzzer" );
    m_stopBuzzer->setGeometry( QRect( 20, 130, 171, 44 ) ); 
    m_stopBuzzer->setText( tr( "StopBuzzer" ) );

    Freq_SpinBox = new QSpinBox( this, "Freq_SpinBox" );
    Freq_SpinBox->setGeometry( QRect( 240, 140, 81, 31 ) ); 
    Freq_SpinBox->setMaxValue( 23000 );
    Freq_SpinBox->setMinValue( 1 );
    Freq_SpinBox->setValue( 1000 );

    Freq_Slider = new QSlider( this, "Freq_Slider" );
    Freq_Slider->setGeometry( QRect( 340, 40, 40, 130 ) ); 
    Freq_Slider->setCursor( QCursor( 0 ) );
    Freq_Slider->setMinValue( 1 );
    Freq_Slider->setMaxValue( 23000 );
    Freq_Slider->setPageStep( 1 );
    Freq_Slider->setValue( 1000 );
    Freq_Slider->setOrientation( QSlider::Vertical );
    Freq_Slider->setTickmarks( QSlider::NoMarks );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 250, 60, 50, 30 ) ); 
    TextLabel1->setText( tr( "Freq" ) );

    // signals and slots connections
    connect( Freq_SpinBox, SIGNAL( valueChanged(int) ), this, SLOT( setFreq() ) );
    connect( Freq_Slider, SIGNAL( valueChanged(int) ), Freq_SpinBox, SLOT( setValue(int) ) );
    connect( Freq_SpinBox, SIGNAL( valueChanged(int) ), Freq_Slider, SLOT( setValue(int) ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QUIForm::~QUIForm()
{
    // no need to delete child widgets, Qt does it all for us
}

void QUIForm::setFreq()
{
    qWarning( "QUIForm::setFreq(): Not implemented yet!" );
}

