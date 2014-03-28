/****************************************************************************
** COMset meta object code from reading C++ file 'comset.h'
**
** Created: Tue Apr 10 00:37:49 2012
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../comset.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *COMset::className() const
{
    return "COMset";
}

QMetaObject *COMset::metaObj = 0;

#ifdef QWS
static class COMset_metaObj_Unloader {
public:
    ~COMset_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "COMset" );
    }
} COMset_metaObj_unloader;
#endif

void COMset::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(COMForm::className(), "COMForm") != 0 )
	badSuperclassWarning("COMset","COMForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString COMset::tr(const char* s)
{
    return qApp->translate( "COMset", s, 0 );
}

QString COMset::tr(const char* s, const char * c)
{
    return qApp->translate( "COMset", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* COMset::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) COMForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (COMset::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (COMset::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    m1_t0 v1_0 = &COMset::openMyCom;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &COMset::Minimize;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "openMyCom()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "Minimize()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"COMset", "COMForm",
	slot_tbl, 2,
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
