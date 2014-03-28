/****************************************************************************
** QDialup meta object code from reading C++ file 'UI_Connect.h'
**
** Created: Thu Mar 29 18:56:55 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/UI_Connect.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QDialup::className() const
{
    return "QDialup";
}

QMetaObject *QDialup::metaObj = 0;

#ifdef QWS
static class QDialup_metaObj_Unloader {
public:
    ~QDialup_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QDialup" );
    }
} QDialup_metaObj_unloader;
#endif

void QDialup::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("QDialup","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QDialup::tr(const char* s)
{
    return qApp->translate( "QDialup", s, 0 );
}

QString QDialup::tr(const char* s, const char * c)
{
    return qApp->translate( "QDialup", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QDialup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QDialup", "QDialog",
	0, 0,
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
