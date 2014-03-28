/****************************************************************************
** QKeyForm meta object code from reading C++ file 'UI_KeyTest.h'
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

#include "../../.ui/release-shared/UI_KeyTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QKeyForm::className() const
{
    return "QKeyForm";
}

QMetaObject *QKeyForm::metaObj = 0;

#ifdef QWS
static class QKeyForm_metaObj_Unloader {
public:
    ~QKeyForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QKeyForm" );
    }
} QKeyForm_metaObj_unloader;
#endif

void QKeyForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QKeyForm","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QKeyForm::tr(const char* s)
{
    return qApp->translate( "QKeyForm", s, 0 );
}

QString QKeyForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QKeyForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QKeyForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QKeyForm", "QWidget",
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
