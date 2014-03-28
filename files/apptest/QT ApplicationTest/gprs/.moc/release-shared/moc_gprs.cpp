/****************************************************************************
** TMainForm meta object code from reading C++ file 'gprs.h'
**
** Created: Mon Apr 23 00:23:06 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../gprs.h"
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
    typedef void (TMainForm::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (TMainForm::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (TMainForm::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    typedef void (TMainForm::*m1_t4)();
    typedef void (QObject::*om1_t4)();
    typedef void (TMainForm::*m1_t5)();
    typedef void (QObject::*om1_t5)();
    typedef void (TMainForm::*m1_t6)();
    typedef void (QObject::*om1_t6)();
    typedef void (TMainForm::*m1_t7)();
    typedef void (QObject::*om1_t7)();
    typedef void (TMainForm::*m1_t8)();
    typedef void (QObject::*om1_t8)();
    typedef void (TMainForm::*m1_t9)();
    typedef void (QObject::*om1_t9)();
    typedef void (TMainForm::*m1_t10)();
    typedef void (QObject::*om1_t10)();
    m1_t0 v1_0 = &TMainForm::numbtnclicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &TMainForm::allmessbtnclicked;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &TMainForm::listenbtnclicked;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &TMainForm::backbtnclicked;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &TMainForm::callbtnclcked;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &TMainForm::messbtnclicked;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &TMainForm::netbtnclicked;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &TMainForm::remoteDataIncoming;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &TMainForm::openMyCom;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &TMainForm::stopbtnclicked;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    m1_t10 v1_10 = &TMainForm::minibtnclicked;
    om1_t10 ov1_10 = (om1_t10)v1_10;
    QMetaData *slot_tbl = QMetaObject::new_metadata(11);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(11);
    slot_tbl[0].name = "numbtnclicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "allmessbtnclicked()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "listenbtnclicked()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "backbtnclicked()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Private;
    slot_tbl[4].name = "callbtnclcked()";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Private;
    slot_tbl[5].name = "messbtnclicked()";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Private;
    slot_tbl[6].name = "netbtnclicked()";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Private;
    slot_tbl[7].name = "remoteDataIncoming()";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Private;
    slot_tbl[8].name = "openMyCom()";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Private;
    slot_tbl[9].name = "stopbtnclicked()";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Private;
    slot_tbl[10].name = "minibtnclicked()";
    slot_tbl[10].ptr = (QMember)ov1_10;
    slot_tbl_access[10] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"TMainForm", "TMainFormBase",
	slot_tbl, 11,
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
