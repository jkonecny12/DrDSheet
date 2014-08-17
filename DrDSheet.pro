TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    src/Storage/character.cpp \
    src/Utils/qmlregistrar.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES +=

HEADERS += \
    src/Storage/character.h \
    src/Utils/qmlregistrar.h
