/****************************************************************************
** QConnectForm meta object code from reading C++ file 'connect.h'
**
** Created: Wed May 2 22:07:54 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../connect.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QConnectForm::className() const
{
    return "QConnectForm";
}

QMetaObject *QConnectForm::metaObj = 0;

#ifdef QWS
static class QConnectForm_metaObj_Unloader {
public:
    ~QConnectForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QConnectForm" );
    }
} QConnectForm_metaObj_unloader;
#endif

void QConnectForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QDialup::className(), "QDialup") != 0 )
	badSuperclassWarning("QConnectForm","QDialup");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QConnectForm::tr(const char* s)
{
    return qApp->translate( "QConnectForm", s, 0 );
}

QString QConnectForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QConnectForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QConnectForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialup::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QConnectForm::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QConnectForm::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (QConnectForm::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (QConnectForm::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    m1_t0 v1_0 = &QConnectForm::runClicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QConnectForm::readOutput;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &QConnectForm::timeOut;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &QConnectForm::setConnectState;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "runClicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "readOutput()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "timeOut()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "setConnectState()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QConnectForm", "QDialup",
	slot_tbl, 4,
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
