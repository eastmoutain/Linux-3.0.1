/****************************************************************************
** QKeyTestForm meta object code from reading C++ file 'keyTest.h'
**
** Created: Wed Jan 26 22:50:48 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../keyTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QKeyTestForm::className() const
{
    return "QKeyTestForm";
}

QMetaObject *QKeyTestForm::metaObj = 0;

#ifdef QWS
static class QKeyTestForm_metaObj_Unloader {
public:
    ~QKeyTestForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QKeyTestForm" );
    }
} QKeyTestForm_metaObj_unloader;
#endif

void QKeyTestForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QKeyForm::className(), "QKeyForm") != 0 )
	badSuperclassWarning("QKeyTestForm","QKeyForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QKeyTestForm::tr(const char* s)
{
    return qApp->translate( "QKeyTestForm", s, 0 );
}

QString QKeyTestForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QKeyTestForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QKeyTestForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QKeyForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QKeyTestForm::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &QKeyTestForm::keyEvent;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "keyEvent()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QKeyTestForm", "QKeyForm",
	slot_tbl, 1,
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
