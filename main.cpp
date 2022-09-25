#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int fontId = QFontDatabase::addApplicationFont("./fonts/interface.ttc");
        QString target_font = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont app_font(target_font);
        QApplication::setFont(app_font);

    w.show();
    return a.exec();


}
