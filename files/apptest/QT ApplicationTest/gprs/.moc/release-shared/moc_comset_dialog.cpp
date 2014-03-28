/****************************************************************************
** COMForm meta object code from reading C++ file 'comset_dialog.h'
**
** Created: Tue Apr 10 00:32:02 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/comset_dialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *COMForm::className() const
{
    return "COMForm";
}

QMetaObject *COMForm::metaObj = 0;

#ifdef QWS
static class COMForm_metaObj_Unloader {
public:
    ~COMForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "COMForm" );
    }
} COMForm_metaObj_unloader;
#endif

void COMForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("COMForm","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString COMForm::tr(const char* s)
{
    return qApp->translate( "COMForm", s, 0 );
}

QString COMForm::tr(const char* s, const char * c)
{
    return qApp->translate( "COMForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* COMForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"COMForm", "QDialog",
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
