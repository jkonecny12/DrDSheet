#include "qmlregistrar.h"

#include <QtQml>

#include "../Storage/character.h"
#include "../Models/charactersmodel.h"

void QmlRegistrar::registerQml()
{
    qmlRegisterType<CharactersModel>("cz.ps.Models", 1, 0, "CharactersModel");
    qmlRegisterType<Character>("cz.ps.Models", 1, 0, "Character");
}
