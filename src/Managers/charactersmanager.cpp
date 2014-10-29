#include "charactersmanager.h"

#include <QMutex>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QtDebug>

#include "../Models/charactersmodel.h"

/*** CONTANTS ***/

#define JS_FILE "charactes.json"

/*** PIMPL ***/

class CharactersManagerPrivate
{
public:
    static CharactersManager *s_instance;
    QScopedPointer<CharactersModel> m_model;

    CharactersManagerPrivate()
    {
        m_model.reset(new CharactersModel());
    }

};

CharactersManager *CharactersManagerPrivate::s_instance = nullptr;

/*** MAIN ***/

CharactersManager::~CharactersManager()
{

}

CharactersManager *CharactersManager::instance()
{
    static QMutex mutex;

    if(!CharactersManagerPrivate::s_instance)
    {
        mutex.lock();

        if(!CharactersManagerPrivate::s_instance)
            CharactersManagerPrivate::s_instance = new CharactersManager();

        mutex.unlock();
    }

    return CharactersManagerPrivate::s_instance;
}

void CharactersManager::dropInstance()
{
    static QMutex mutex;

    if(CharactersManagerPrivate::s_instance)
    {
        mutex.lock();

        if(CharactersManagerPrivate::s_instance)
            delete CharactersManagerPrivate::s_instance;

        mutex.unlock();
    }
}

CharactersModel *CharactersManager::model() const
{
    Q_D(const CharactersManager);

    return d->m_model.data();
}

void CharactersManager::readCharacters(const QJsonObject &json)
{
    Q_D(CharactersManager);

    d->m_model->read(json);
}

void CharactersManager::writeCharacters(QJsonObject &json) const
{
    Q_D(const CharactersManager);

    d->m_model->write(json);
}

bool CharactersManager::loadCharacters()
{
    const QString path = QStandardPaths::locate(QStandardPaths::StandardLocation::DataLocation,
                                                QStringLiteral(JS_FILE),
                                                QStandardPaths::LocateOption::LocateFile);

    QFile loadFile(path);

    if(!loadFile.open(QFile::OpenModeFlag::ReadOnly))
    {
        qWarning("Can't load file");
        return false;
    }

    QByteArray byteArray = loadFile.readAll();
    QJsonParseError error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(byteArray, &error));

    if(error.error != QJsonParseError::ParseError::NoError)
    {
        qWarning("Can't read json object");
        qWarning() << error.errorString();
        return false;
    }

    this->readCharacters(jsonDoc.object());

    return true;
}

bool CharactersManager::writeCharacters() const
{
    const QString path = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DataLocation);

    QFile saveFile(path);

    if(!saveFile.open(QFile::OpenModeFlag::WriteOnly))
    {
        qWarning("Can't write file");
        return false;
    }

    QJsonObject writeJson;
    writeCharacters(writeJson);
    QJsonDocument jsonDoc(writeJson);
    saveFile.write(jsonDoc.toJson());

    return true;
}

CharactersManager::CharactersManager(QObject *parent) :
    QObject(parent),
    d_ptr(new CharactersManagerPrivate())
{
}
