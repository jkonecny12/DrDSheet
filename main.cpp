#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/Utils/qmlregistrar.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlRegistrar::registerQml();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
