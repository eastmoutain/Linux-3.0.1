#if !defined (__SCAN_MES_H__) 
# define __SCAN_MES_H__

#include <qtopia/qprocess.h>

#include "scanmes_dialog.h"
#include "messdialog.h"

class ScanMessDialog: public ScanMessForm
{
	Q_OBJECT 
public:

	ScanMessDialog(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);
private:
	QString unicodeToString(QString str);
	QString gsmEncodeToUnicode(QString strSrc);
	QString ProcessMessage( QString strMsg);
	QString Bit7Decode(QString &strSrc);
	QString DecToUnicode(QString strSrc);
	int GSMDecode7bit( const unsigned char *pSrc, char *pDst, int nSrcLength );
	

private slots: 
	void scanbtnclicked();
	void readScanningOutput();
	void doubleClicked(QListViewItem* item);
	
}; 

#endif
