#include "mainform.h"
#include <QApplication>
#include <QDebug>
#include <QScreen>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // ide -> local -> retome
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gbk"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));
    MainForm w;
    w.show();

    return a.exec();
}
