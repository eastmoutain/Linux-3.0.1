#include "scanmes.h"
#include <qpushbutton.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qmultilineedit.h>
#include <qlistview.h> 
#include <qlistview.h>
#include <qtopia/qpeapplication.h>

extern int m_fd;
extern QString num;
QString meslist[10];
QString formtelnumStr;
QString messageStr;
QString fullmesInfo;
QString witch_slected;
QString messtime;
ScanMessDialog::ScanMessDialog(QWidget * parent, const char * name, WFlags f):ScanMessForm(parent, name, f)
{
	connect( m_ListView, SIGNAL(doubleClicked(QListViewItem*) ), this, SLOT(doubleClicked(QListViewItem*) ) );
	connect(scan_btn,SIGNAL(clicked()),this,SLOT(scanbtnclicked()));
		
	m_ListView->removeColumn(0);
	
	m_ListView->addColumn(tr("all Mes"));
	m_ListView->addColumn(tr("time"));
	m_ListView->addColumn(tr("num"));
	m_ListView->addColumn(tr("state"));	
}

void ScanMessDialog::doubleClicked(QListViewItem* item)
{
		QListViewItem * cur = (QListViewItem*)m_ListView->currentItem();	
		if(NULL!=cur)		
		{
			QString mes_num=cur->text(0);
			//QMessageBox::information(this,"gprs",mes_num);
			witch_slected=mes_num;		
		}
		
        MesDialog *wdg = new MesDialog(this );
        
        if(QPEApplication::execDialog(wdg) == QDialog::Accepted)
        {
		  
        }
        delete wdg;
}
void ScanMessDialog::scanbtnclicked()
{	
	
	m_ListView->clear();
	
	::write(m_fd,"AT+CMGL=4\r",strlen("AT+CMGL=4\r"));
	sleep(1);
		//QMessageBox::information(this,"gprs","AT+CMGL=4",0);
	
	readScanningOutput();
	
}

void ScanMessDialog::readScanningOutput()
{
	
	char getch[8192];

	::read(m_fd,getch,8192);
	sleep(1);
	//QMessageBox::information(this,tr(""),tr(getch));	
	
     fullmesInfo = QString(getch);
	//QMessageBox::information(this,"gprs",fullmesInfo);
	
	if(fullmesInfo.find("OK")==-1)
	{
		QMessageBox::information(this,"gprs","NOT ALL MESSAGES",0);
	}

	int i = fullmesInfo.contains( "+CMGL:", FALSE );  	

     for(int j=0;j<i;j++)///fullmesInfo="+CMGL:1,1,,  .......+CMGL:1,1,,........."
	{
		QString stateStr;
     	int CMGLIndex=fullmesInfo.find("+CMGL:");
		QString removeCMGL=fullmesInfo.remove(0,CMGLIndex+6);//removeCMGL="1,1,,........+CMGL:...."
		//QMessageBox::information(this,"gprs",removeCMGL);
		int nextmesIndex=removeCMGL.find("+CMGL:");
		stateStr=removeCMGL.left(nextmesIndex);//stateStr="1,1,,,.........."
		fullmesInfo=removeCMGL;
		//QMessageBox::information(this,"gprs",stateStr);
		//QMessageBox::information(this,"gprs",ProcessMessage(stateStr));

		QString all_mes_num=stateStr.left( 2 ); //all_mes_num="1"
     				
     	int stateIndex=stateStr.find(",");			
		QString state=stateStr.remove(0,stateIndex+1).left( 1 );//state=1
		
		bool ok=false;
		int mes_read_num=all_mes_num.toInt(&ok);
		meslist[mes_read_num]=ProcessMessage(stateStr);
			
		QListViewItem *lvi=  new QListViewItem(m_ListView, all_mes_num,messtime,formtelnumStr,state);
        
	}  
}

QString ScanMessDialog::ProcessMessage( QString strMsg)
{
    char *strmb="From: ";
    char *strdd="Time: "; 
    char *strcontent="Content: ";			
    QString ctrlouttmp;
    QString strupper;
    //const char *ctrlout;
    int n, i,numlen, len ,PDUIndex;
    QString strData,strSrc,strDes,nType,strPDULength;
    QString strnumber , strdate, strnumtmp,strdatetmp;
    QString messagecontent;				
    // find the last "," first
    n = strMsg.findRev(',');				
    // get the PDU data length
    PDUIndex=strMsg.find("089168");
    strPDULength = strMsg.mid(n+1,PDUIndex-n-1);
    //QMessageBox::information(this,"gprs",strPDULength);
       
    // get the TPDU content
    strData = strMsg.mid(PDUIndex+18,1024);	
    //QMessageBox::information(this,"gprs",strData);		
    // get the mobile phone number
	bool ok=false;
	numlen=strData.mid(2,2).toInt(&ok,16);

	//QMessageBox::information(this,"gprs",strData.mid(2,2));
    	strnumber=strData.mid(6,numlen+1);	//modify 6,12

    	// decode the mobile phone number
    	len=strnumber.length();
    	for(i=0;i<len-2;i=i+2)		
    	{
		strnumtmp+=strnumber.mid(i+1,1);
		strnumtmp+=strnumber.mid(i,1);
    	}
    	strnumtmp+=strnumber.mid(i+1,1);
	formtelnumStr=strnumtmp;

   	// 1. add the decoded mobile phone number into the message content
    	messagecontent+=QString( strmb+strnumtmp+"\n" );		
    	// get the date and time
	
	if(numlen%2==0)
	{
		numlen=numlen-1;
    	}
	strdate=strData.mid(numlen+11,12);	//22,12
    	len=strdate.length();
	// decode the date and time
    	for(i=0;i<len;i=i+2)		
    	{
		strdatetmp+=strdate.mid(i+1,1);
		strdatetmp+=strdate.mid(i,1);
		if(i<4)
		strdatetmp+="-";
		if(i==4)
		strdatetmp+="  ";
		if((i>4)&&(i<10))
		strdatetmp+=":";
    	}	
	messtime=strdatetmp;
    	// 2. add the decoded date & time into the message content
    	messagecontent+=QString( strdd+strdatetmp+"\n" );				
    	nType=strData.mid(numlen+9,2);//20,2
    	// get the content string
	//strSrc = strData.mid(40,(nPDULength-19)*2);  	//	
	strSrc = strData.mid(numlen+27,300);
	//QMessageBox::information(this,"gprs strSrc ",strSrc );
    	if(nType.find("00",false)>=0)
	// 7 bits decoding
	strDes=Bit7Decode(strSrc);
    	else
	// PDU decoding ( it's what we use in this contest )
	strDes=DecToUnicode(strSrc); 	
    	strDes=strDes.lower();
    	// 3. add the decoded date & time into the message content
    	messagecontent+=QString(strcontent+strDes+"\n");			
   	//return strDes;
    	return messagecontent;
}

QString ScanMessDialog::Bit7Decode(QString &strSrc)
{
	unsigned char pDst[4096]; 
	char pSrc[4096]; 
	int i, length;	
	int strlength=strSrc.length(); 
	for(i=0;i<strlength;i++) 
	{ 
		pSrc[i]=strSrc.at(i).latin1(); 	
	}	 
	for(i=0;  i<strlength;i=i+2) 
	{ 
		char c[2]; 
		char *p; 
		unsigned long t; 
		c[0]=pSrc[i]; 
		c[1]=pSrc[i+1]; 
		t=strtoul (c,&p,16); 
		pDst[i/2]=t;   
	}	 
	length=GSMDecode7bit(pDst,pSrc,strlength/2);
	QString textout=pSrc; 
	return textout;
}

QString ScanMessDialog::DecToUnicode(QString strSrc)
{
	int strlength;
	QString strMsgtmp,str0;
	bool ok;
	QString strMsgout;
	ushort num;
	strlength=strSrc.length();
	const ushort *data;
	for(int i=0;i<strlength;i=i+4)
	{
	    str0=strSrc.mid(i,4);
	    num=str0.toUShort(&ok,16);
	    data=&num;
	    strMsgtmp=strMsgtmp.setUnicodeCodes(data,1);
	    strMsgout+=strMsgtmp;	
	}
	return strMsgout;
}

int ScanMessDialog::GSMDecode7bit( const unsigned char *pSrc, char *pDst, int nSrcLength )
{
	int nSrc=0;  
	int nDst=0;  
	int nByte=0;  
	unsigned char nLeft=0; 
	while(nSrc<nSrcLength)
	{
	    *pDst = ((*pSrc << nByte) | nLeft) & 0x7f;
	    nLeft = *pSrc >> (7-nByte);	
	    pDst++;
	    nDst++;
	    nByte++;
	    if(nByte == 7)
	    {
		*pDst = nLeft ;
		pDst++;
		nDst++;
		nByte = 0;
		nLeft = 0;
	    }
	    pSrc++;
	    nSrc++;
	}	
	*pDst = 0;
	return nDst; 
}

