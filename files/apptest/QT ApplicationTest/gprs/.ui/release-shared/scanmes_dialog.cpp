/****************************************************************************
** Form implementation generated from reading ui file 'scanmes_dialog.ui'
**
** Created: Mon Apr 23 20:21:09 2012
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "scanmes_dialog.h"

#include <qheader.h>
#include <qlabel.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"191 61 37 1",
"f c #0e6eb8",
"d c #1d77bc",
"n c #231815",
"w c #2c80c1",
"u c #312624",
"y c #3b89c5",
"t c #3f3532",
"e c #4a92ca",
"o c #4c4341",
"h c #5a5250",
"a c #5a9bce",
"i c #68605e",
"C c #69a5d3",
"m c #766f6d",
"E c #78aed7",
"s c #847d7c",
"b c #86b6db",
"k c #918b8a",
"A c #95bfe0",
"r c #9e9a98",
"c c #a4c8e4",
"j c #aca8a7",
"D c #b3d2e9",
"v c #bab7b6",
"B c #c3dbed",
"p c #c8c5c4",
"# c #d2e4f2",
"g c #d6d4d3",
"z c #e1edf6",
"l c #e3e2e2",
"x c #f0f6fb",
"q c #f1f1f0",
"I c #f6f6f6",
"H c #f7f7f7",
"G c #f8f8f8",
"F c #f9f9f9",
". c #fbfbfb",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
"...............................................................................................................................................................................................",
".....................#a...bc.........#a...bc...................................................................................................................................................",
"....................#de...bfc.......#de...bfc..................................................................................................................................................",
"...................#dfe...bffc.....#dfe...bffc.................................................................................................................................................",
"..................#dffe...bfffc...#dffe...bfffc..................ghhhhhhhhhhhij............jkkkl......mnnno.........ppppq...nnnnj...ppppq.......ghhhhg.....................pnnnr.qkkkj.........",
"..................bfffe...bfffe...bfffe...bffff..................lkkkkkkkkmnnnns.....gtl...hnnnp......hnnnm........qnnnng..gnnnnp..lnnnnl........unnnk.....................pnnnp.hnnnv.........",
"..................bfffe...bfffe...bfffe...bffff............................knnnt....qonoq..hnnnv.rhhhhnnnnthhhhs...pnnnn...vnnnn...vnnnu.........mnnno.....................jnnnpmnnns..........",
"..................bfffe...bfffe...bfffe...bffff............................jnnnt....innnh..knnnk.jkkkmnnnnmkkkkj...rnnno...knnno...snnnh.........vnnnnl....................knnnihhhk...........",
"..................bfffe...bfffe...bfffe...bffff..#c........................knnnh...snnnnj..knnnk.....vnnnnl........snnnumkkonnntkkinnnnk.........qnnnnj........knnnnnnnnnnnnnnnnnnnnnk.........",
".............#a...bfffe...bfffe...bfffe...bfffw.xyfc.......................hnnnk..jnnnns...knnnkpppppmnnnnppppppq..shhhhhhhhhhhhhhhhhij...........nnnni........lpppppppppppmnnnrpppppl.........",
"............#de...bfffe...bfffe...bfffe...bfffa.aff#z......................tnnnj.gunnnh....knnnmhhhhhhhhhhhhhhhhl..pppl.jhhhl..rkkj..............qnnnnn....................innnq...............",
"...........#dfe...bfffe...bfffe...bfffe...bfff#bffAcfc....................qnnnngqtnnnoq....rnnnh..ihhhk.shhhm.....pnnnk.hnnn..pnnnj..............jnnnnnv...................hnnn................",
"..........#dffe...bfffe...bfffe...bfffe...effABffC#dffc...................pnnnn.hnnnug.....knnnk.mnnnuq.jnnnnp....jnnnp.tnno..hnnnnnnnh..........tnnnnns...................hnnn................",
".........#dfffe...bfffe...bfffe...bfffe..Dffazdfyzyffffc..................rnnno.nnnnj......knnnkmnnnug...tnnntq...snnnl.nnni.vnnnmkknnnl........rnnnnnnt.......pkkkkkkkkkkphnnn................",
"........#dffffe...bfffe...bfffe...bfffe.zdfwxyffBCffffffc.................snnni.tnnnm......hnnnunnnnikp..gonnnol.nnnnnnnnnnnnnnnh...nnnq.......pnnnnnnnng......pkksnnnnkkkphnnn................",
".......#dfffffe...bfffe...bfffe...bfffExyff#Cfff.dfffffffc................hnnnk.gnnnnm.....nnnnppmnnnnohhhhhtkpq..unnh.jnnnpsnnnnnnsnnt.......lunnntnnnnr.........pnnnh....hnnu................",
"......#dffffffe...bfffe...bfffe...bffdxCffccfffe.fffffffffc...............nnnnp..jnnnnj...vnnno.pnnnuvppphnnnu...qnnnm.snnnjnnnnnntvnnh......qonnnuqunnno.........rnnni....nnnh................",
".....#dfffffffe...bfffe...bfffe...wff#AffC#ffffe.ffffffffffc.............lnnnnl...snnnnj..innnrgunnnv...gunnnh...pnnnr.hnnnjkkinnnplppl......mnnnng.mnnnnq........snnnk....nnnh................",
"....#dffffffffe...bfffe...bfffe..AffABffwxwffffe.fffffffffffc............pnnnn.....mnnnuglnnnultnnnnoq.rnnnnoq...knnnrpunnh..qtnnnm.........rnnnnj..jnnnnj........hnnnv....nnnh................",
"....dfffffffffe...bfffe...bfffe.#ffCzdffcAfffffe.ffffffffffffD...........knnnh.....qonnntknnnoonnnnnnohnnnnmq....mnnnhonnns..snnnnng.......pnnnnm...qnnnnm........nnnng....nnnh................",
"....cfffffffffe...bfffe...bfffAxdfyzyfffBafffffe.fffffffffffyx...........hnnns......qunugtnnnskkkpunnnnnnuv......hnnt.pnnnr.vnnnnnns......lunnno.....hnnnu.......lnnnn.....nnnh................",
".....cffffffffe...bfffe...Effy.yfd#Cffff.efffffe.ffffffffffyx............onnns.......gupvnnno.....gnnnnniq.......nnnh.knnnpqunnunnnu.....qonnnuq.....rnnnnp......pnnno....lnnno................",
"......cfffffffe...bfffe...wfdzEffccfffff.efffffe.fffffffffyx.............tnnntq.......l.innnj...qkunnnnnup......gnnnk.mnnnqhnnnvonnnv....mnnnng......gnnnns......knnni....pnnnnkl..............",
".......cffffffe...bfffe..bffDcffazdfffff.efffffe.ffffffffyx..............innnnuhhhhhhhhhnnnnq..jtnnnuhnnnnsq....vnnnj.tnntsnnnm.jnnni...jnnnnr........tnnno......mnnnk....lnnnnnnnnl...........",
"........cfffffe...bfffe.BffE#dffBbffffff.efffffe.fffffffyx...............gunnnnnnnnnnnnnnnni.jtnnnnml.vunnnuj...knnniinnninnntq.qunnnq.gnnnnm.........mnnnnlqhhhhunnnthhhv.hnnnnnnn............",
".........cffffe...bfffcxdfyxwfff.effffff.efffffe.ffffffyx.................qrhhhhhhhhhhhhhhhjmhhhhml....lihhhhk..khhhhhhkgihhhp...khhhvqunnnoq.........vnnnnrghhhhhhhhhhhhg.ginnnnnt............",
"..........cfffe...Effy.yfdxaffff.effffff.efffffe.fffffyx.......................................................................................................................................",
"...........cffe...wfdzEffBbfffff.effffff.efffffe.ffffyx........................................................................................................................................",
"............cfe..bffDcffCBffffff.effffff.efffffe.fffyx.........................................................................................................................................",
".............ce.Dffb#dff#Cffffff.effffff.efffffe.ffyx..............gkkkkl..lrkrl...vkkjq..jp....pk..kv...jp.jj..qkp....vkkkk..jk....rj..pkkjl..pkkkkl.vkkrg...qjkkjl...pkkkk..vkkrg............",
"..............##dfaxwfff.effffff.effffff.efffffe.fyx...............ktkkkl.jnmkhnv..nmktu..uk....sh..nuq..uj.knl.moq....hhkkk..unl..vnh..ohkouq.itkkk.qnmkmuoq.rnkkhnk..hhkkk.gnmkmnh...........",
"...............Dfyxaffff.effffff.effffff.efffffe.yx................ii....vnv...hh.png.pnlqnp....hm.pntm.qng.qtmmug.....nr....gntj.qtui..nv.vnl.ok....pnq..gnr.sh...rnl.uk....vn...gnj..........",
"................c#bfffff.effffff.effffff.efffffe...................thkkp.om....ku.jnpvom.pnq....ur.rtjnppn...jnug.....lnmkkl.rohm.shhk.gnmmuj..nikkp.ku....tk.hs...pnpqnmkkp.ko....nk..........",
".................zffffff.efffffC.cffffff.efffffa...................nmkkp.nk....ih.kuhtt..ru....lnp.sh.ohko...mnt......pnkkkl.isktgnghk.jnpkum.pnskkg.mh...qnj.nr...jnqpnkkkl.ii...lnv..........",
"..................cfffff.effffC...cfffff.effffyx..................pnl....us...pnv.hm.gnp.mh....pnq.hk.pnhi..juvnr.....kt.....uvpnhs.nv.kh..su.jn.....hs...itqlnp..lus.ru.....tk..qio...........",
"...................cffff.efffC.....cffff.efffyx...................jn.....knkpkus..uk..nv.hokkk.ku..uv..mnk.jnp.muq....itkkklgnq.ntq.np.hhpsur.kukkkl.nspkttg.pnvvsuiq.mtkkkl.nkpktog...........",
"....................cfff.effC.......cfff.effyx....................pj......jihsp...kl..kp.kkkkk.pj..kl..lkg.kv..lkg....jkkkkqpr..jp.qkl.jhikp..jkkkkl.shikv...pihmkg...jkkkkllmhikv.............",
"FFFFFFFFFFFFFFFFFFFFFcffFefCFFFFFFFFFcffFefyxFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
"FFFFFFFFFFFFFFFFFFFFFFEfFeCFFFFFFFFFFFcfFeyxFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
"FFFFFFFFFFFFFFFFFFFFFFFEFcFFFFFFFFFFFFFcFbxFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH",
"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH",
"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH",
"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII",
"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"};


/* 
 *  Constructs a ScanMessForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ScanMessForm::ScanMessForm( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "ScanMessForm" );
    resize( 480, 255 ); 
    setMaximumSize( QSize( 480, 255 ) );
    setCaption( tr( "Scan_Mess" ) );

    PixmapLabel1 = new QLabel( this, "PixmapLabel1" );
    PixmapLabel1->setGeometry( QRect( 280, 130, 190, 60 ) ); 
    PixmapLabel1->setPixmap( image0 );
    PixmapLabel1->setScaledContents( TRUE );

    scan_btn = new QPushButton( this, "scan_btn" );
    scan_btn->setGeometry( QRect( 300, 40, 150, 44 ) ); 
    scan_btn->setText( tr( "scan all mes" ) );

    m_ListView = new QListView( this, "m_ListView" );
    m_ListView->addColumn( tr( "Column 1" ) );
    QListViewItem * item = new QListViewItem( m_ListView, 0 );
    item->setText( 0, tr( "New Item" ) );

    m_ListView->setGeometry( QRect( 0, 10, 270, 220 ) ); 
}

/*  
 *  Destroys the object and frees any allocated resources
 */
ScanMessForm::~ScanMessForm()
{
    // no need to delete child widgets, Qt does it all for us
}

