/****************************************************************************
** NetDialog meta object code from reading C++ file 'netdialog.h'
**
** Created: Thu Apr 19 22:09:24 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../netdialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *NetDialog::className() const
{
    return "NetDialog";
}

QMetaObject *NetDialog::metaObj = 0;

#ifdef QWS
static class NetDialog_metaObj_Unloader {
public:
    ~NetDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "NetDialog" );
    }
} NetDialog_metaObj_unloader;
#endif

void NetDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(NetdialogForm::className(), "NetdialogForm") != 0 )
	badSuperclassWarning("NetDialog","NetdialogForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString NetDialog::tr(const char* s)
{
    return qApp->translate( "NetDialog", s, 0 );
}

QString NetDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "NetDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* NetDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) NetdialogForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (NetDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (NetDialog::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (NetDialog::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    m1_t0 v1_0 = &NetDialog::startbtnclicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &NetDialog::readOutput;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &NetDialog::stopbtnclicked;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "startbtnclicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "readOutput()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "stopbtnclicked()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"NetDialog", "NetdialogForm",
	slot_tbl, 3,
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
