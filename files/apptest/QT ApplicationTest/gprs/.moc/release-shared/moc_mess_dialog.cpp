/****************************************************************************
** QMesDialog meta object code from reading C++ file 'mess_dialog.h'
**
** Created: Wed Apr 25 22:47:44 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/mess_dialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QMesDialog::className() const
{
    return "QMesDialog";
}

QMetaObject *QMesDialog::metaObj = 0;

#ifdef QWS
static class QMesDialog_metaObj_Unloader {
public:
    ~QMesDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QMesDialog" );
    }
} QMesDialog_metaObj_unloader;
#endif

void QMesDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("QMesDialog","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QMesDialog::tr(const char* s)
{
    return qApp->translate( "QMesDialog", s, 0 );
}

QString QMesDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "QMesDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QMesDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QMesDialog", "QDialog",
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
