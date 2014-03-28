/****************************************************************************
** ScanMessForm meta object code from reading C++ file 'scanmes_dialog.h'
**
** Created: Mon Apr 23 20:21:11 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/scanmes_dialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *ScanMessForm::className() const
{
    return "ScanMessForm";
}

QMetaObject *ScanMessForm::metaObj = 0;

#ifdef QWS
static class ScanMessForm_metaObj_Unloader {
public:
    ~ScanMessForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "ScanMessForm" );
    }
} ScanMessForm_metaObj_unloader;
#endif

void ScanMessForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("ScanMessForm","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString ScanMessForm::tr(const char* s)
{
    return qApp->translate( "ScanMessForm", s, 0 );
}

QString ScanMessForm::tr(const char* s, const char * c)
{
    return qApp->translate( "ScanMessForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* ScanMessForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"ScanMessForm", "QDialog",
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
