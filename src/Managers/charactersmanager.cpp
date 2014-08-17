#include "charactersmanager.h"

#include <QMutex>

#include "../Models/charactersmodel.h"

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

const CharactersManager *CharactersManager::instance()
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

CharactersManager::CharactersManager(QObject *parent) :
    QObject(parent),
    d_ptr(new CharactersManagerPrivate())
{
}
