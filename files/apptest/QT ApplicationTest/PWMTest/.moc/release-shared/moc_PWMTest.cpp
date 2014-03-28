/****************************************************************************
** QPWMTest meta object code from reading C++ file 'PWMTest.h'
**
** Created: Mon Mar 12 02:26:25 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../PWMTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QPWMTest::className() const
{
    return "QPWMTest";
}

QMetaObject *QPWMTest::metaObj = 0;

#ifdef QWS
static class QPWMTest_metaObj_Unloader {
public:
    ~QPWMTest_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QPWMTest" );
    }
} QPWMTest_metaObj_unloader;
#endif

void QPWMTest::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QUIForm::className(), "QUIForm") != 0 )
	badSuperclassWarning("QPWMTest","QUIForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QPWMTest::tr(const char* s)
{
    return qApp->translate( "QPWMTest", s, 0 );
}

QString QPWMTest::tr(const char* s, const char * c)
{
    return qApp->translate( "QPWMTest", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QPWMTest::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QUIForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QPWMTest::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QPWMTest::*m1_t1)(int);
    typedef void (QObject::*om1_t1)(int);
    m1_t0 v1_0 = &QPWMTest::buttonClicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QPWMTest::setFreq;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "buttonClicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "setFreq(int)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QPWMTest", "QUIForm",
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
