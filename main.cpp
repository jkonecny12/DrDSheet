#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/Utils/qmlregistrar.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DrDSheetMain sheet;
    sheet.registerQml();

    QObject::connect(&app, &QGuiApplication::aboutToQuit, &sheet, &DrDSheetMain::freeResources);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
