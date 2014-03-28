/****************************************************************************
** QKeyTestForm meta object code from reading C++ file 'dialog.h'
**
** Created: Sun Feb 20 19:40:43 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../dialog.h"
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
    if ( qstrcmp(Form::className(), "Form") != 0 )
	badSuperclassWarning("QKeyTestForm","Form");
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
    (void) Form::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QKeyTestForm", "Form",
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
