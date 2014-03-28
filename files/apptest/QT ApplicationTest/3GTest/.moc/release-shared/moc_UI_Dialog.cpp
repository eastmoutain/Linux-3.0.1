/****************************************************************************
** Form meta object code from reading C++ file 'UI_Dialog.h'
**
** Created: Sun Feb 20 19:40:44 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/UI_Dialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *Form::className() const
{
    return "Form";
}

QMetaObject *Form::metaObj = 0;

#ifdef QWS
static class Form_metaObj_Unloader {
public:
    ~Form_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "Form" );
    }
} Form_metaObj_unloader;
#endif

void Form::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("Form","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Form::tr(const char* s)
{
    return qApp->translate( "Form", s, 0 );
}

QString Form::tr(const char* s, const char * c)
{
    return qApp->translate( "Form", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Form::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Form", "QDialog",
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
