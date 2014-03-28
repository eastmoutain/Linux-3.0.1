#include <QtGui/QApplication>
#include <QTextCodec>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    //中文支持
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
     QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));        //支持中文
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //支持中文文件名显示
     QFont font;
     //font.setPointSize(160); //16的字号
     font.setPixelSize(16);
     font.setFamily(("wenquanyi"));
     font.setBold(false);

     a.setFont(font);

     w.show();

    return a.exec();
}
