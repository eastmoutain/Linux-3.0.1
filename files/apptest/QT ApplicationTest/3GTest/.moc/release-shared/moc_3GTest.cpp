/****************************************************************************
** QMainForm meta object code from reading C++ file '3GTest.h'
**
** Created: Thu Mar 29 19:45:07 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../3GTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QMainForm::className() const
{
    return "QMainForm";
}

QMetaObject *QMainForm::metaObj = 0;

#ifdef QWS
static class QMainForm_metaObj_Unloader {
public:
    ~QMainForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QMainForm" );
    }
} QMainForm_metaObj_unloader;
#endif

void QMainForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QBaseForm::className(), "QBaseForm") != 0 )
	badSuperclassWarning("QMainForm","QBaseForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QMainForm::tr(const char* s)
{
    return qApp->translate( "QMainForm", s, 0 );
}

QString QMainForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QMainForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QMainForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QBaseForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QMainForm::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QMainForm::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (QMainForm::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    m1_t0 v1_0 = &QMainForm::pushWCDMAlicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QMainForm::pushCDMA2000licked;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &QMainForm::pushTDSCDMAlicked;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "pushWCDMAlicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "pushCDMA2000licked()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "pushTDSCDMAlicked()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QMainForm", "QBaseForm",
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
