/****************************************************************************
** TMainForm meta object code from reading C++ file 'ledtest.h'
**
** Created: Fri Feb 11 22:54:11 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../ledtest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *TMainForm::className() const
{
    return "TMainForm";
}

QMetaObject *TMainForm::metaObj = 0;

#ifdef QWS
static class TMainForm_metaObj_Unloader {
public:
    ~TMainForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "TMainForm" );
    }
} TMainForm_metaObj_unloader;
#endif

void TMainForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(TMainFormBase::className(), "TMainFormBase") != 0 )
	badSuperclassWarning("TMainForm","TMainFormBase");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString TMainForm::tr(const char* s)
{
    return qApp->translate( "TMainForm", s, 0 );
}

QString TMainForm::tr(const char* s, const char * c)
{
    return qApp->translate( "TMainForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* TMainForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) TMainFormBase::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (TMainForm::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &TMainForm::checkBoxClicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "checkBoxClicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"TMainForm", "TMainFormBase",
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
