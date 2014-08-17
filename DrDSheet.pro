TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    src/Storage/character.cpp \
    src/Models/charactersmodel.cpp \
    src/Managers/charactersmanager.cpp \
    src/Utils/drdsheetmain.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES +=

HEADERS += \
    src/Storage/character.h \
    src/Models/charactersmodel.h \
    src/Managers/charactersmanager.h \
    src/Utils/drdsheetmain.h
