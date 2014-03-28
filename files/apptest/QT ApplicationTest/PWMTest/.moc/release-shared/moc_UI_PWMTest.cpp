/****************************************************************************
** QUIForm meta object code from reading C++ file 'UI_PWMTest.h'
**
** Created: Tue Apr 24 20:57:42 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/UI_PWMTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QUIForm::className() const
{
    return "QUIForm";
}

QMetaObject *QUIForm::metaObj = 0;

#ifdef QWS
static class QUIForm_metaObj_Unloader {
public:
    ~QUIForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QUIForm" );
    }
} QUIForm_metaObj_unloader;
#endif

void QUIForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QUIForm","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QUIForm::tr(const char* s)
{
    return qApp->translate( "QUIForm", s, 0 );
}

QString QUIForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QUIForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QUIForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QUIForm::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &QUIForm::setFreq;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "setFreq()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"QUIForm", "QWidget",
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
