/****************************************************************************
** ScanMessDialog meta object code from reading C++ file 'scanmes.h'
**
** Created: Mon Apr 23 00:45:45 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../scanmes.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *ScanMessDialog::className() const
{
    return "ScanMessDialog";
}

QMetaObject *ScanMessDialog::metaObj = 0;

#ifdef QWS
static class ScanMessDialog_metaObj_Unloader {
public:
    ~ScanMessDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "ScanMessDialog" );
    }
} ScanMessDialog_metaObj_unloader;
#endif

void ScanMessDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ScanMessForm::className(), "ScanMessForm") != 0 )
	badSuperclassWarning("ScanMessDialog","ScanMessForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString ScanMessDialog::tr(const char* s)
{
    return qApp->translate( "ScanMessDialog", s, 0 );
}

QString ScanMessDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "ScanMessDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* ScanMessDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ScanMessForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (ScanMessDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (ScanMessDialog::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (ScanMessDialog::*m1_t2)(QListViewItem*);
    typedef void (QObject::*om1_t2)(QListViewItem*);
    m1_t0 v1_0 = &ScanMessDialog::scanbtnclicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &ScanMessDialog::readScanningOutput;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &ScanMessDialog::doubleClicked;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "scanbtnclicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "readScanningOutput()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "doubleClicked(QListViewItem*)";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"ScanMessDialog", "ScanMessForm",
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
