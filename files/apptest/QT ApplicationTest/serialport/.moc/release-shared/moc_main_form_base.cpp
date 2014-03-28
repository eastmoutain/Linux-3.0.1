/****************************************************************************
** TMainFormBase meta object code from reading C++ file 'main_form_base.h'
**
** Created: Thu Apr 26 00:55:07 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/main_form_base.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *TMainFormBase::className() const
{
    return "TMainFormBase";
}

QMetaObject *TMainFormBase::metaObj = 0;

#ifdef QWS
static class TMainFormBase_metaObj_Unloader {
public:
    ~TMainFormBase_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "TMainFormBase" );
    }
} TMainFormBase_metaObj_unloader;
#endif

void TMainFormBase::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("TMainFormBase","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString TMainFormBase::tr(const char* s)
{
    return qApp->translate( "TMainFormBase", s, 0 );
}

QString TMainFormBase::tr(const char* s, const char * c)
{
    return qApp->translate( "TMainFormBase", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* TMainFormBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (TMainFormBase::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &TMainFormBase::sendButtonClicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "sendButtonClicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"TMainFormBase", "QWidget",
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
