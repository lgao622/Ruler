#include "mainform.h"
#include <QApplication>
#include <QDebug>
#include <QScreen>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // ide -> local -> retome
    QApplication a(argc, argv);
    MainForm w;
    w.show();

    return a.exec();
}
