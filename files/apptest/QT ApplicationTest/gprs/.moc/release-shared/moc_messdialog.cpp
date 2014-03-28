/****************************************************************************
** MesDialog meta object code from reading C++ file 'messdialog.h'
**
** Created: Mon Apr 23 19:58:25 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../messdialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *MesDialog::className() const
{
    return "MesDialog";
}

QMetaObject *MesDialog::metaObj = 0;

#ifdef QWS
static class MesDialog_metaObj_Unloader {
public:
    ~MesDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "MesDialog" );
    }
} MesDialog_metaObj_unloader;
#endif

void MesDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QMesDialog::className(), "QMesDialog") != 0 )
	badSuperclassWarning("MesDialog","QMesDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString MesDialog::tr(const char* s)
{
    return qApp->translate( "MesDialog", s, 0 );
}

QString MesDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "MesDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* MesDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMesDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (MesDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &MesDialog::sendbtnclicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "sendbtnclicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"MesDialog", "QMesDialog",
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
