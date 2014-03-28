/****************************************************************************
** NetdialogForm meta object code from reading C++ file 'net_dialog.h'
**
** Created: Wed Apr 25 23:46:13 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/net_dialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *NetdialogForm::className() const
{
    return "NetdialogForm";
}

QMetaObject *NetdialogForm::metaObj = 0;

#ifdef QWS
static class NetdialogForm_metaObj_Unloader {
public:
    ~NetdialogForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "NetdialogForm" );
    }
} NetdialogForm_metaObj_unloader;
#endif

void NetdialogForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("NetdialogForm","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString NetdialogForm::tr(const char* s)
{
    return qApp->translate( "NetdialogForm", s, 0 );
}

QString NetdialogForm::tr(const char* s, const char * c)
{
    return qApp->translate( "NetdialogForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* NetdialogForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"NetdialogForm", "QDialog",
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
