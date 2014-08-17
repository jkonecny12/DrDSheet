#include "qmlregistrar.h"

#include <QtQml>

#include "../Storage/character.h"

void QmlRegistrar::registerQml()
{
    qmlRegisterType<Character>("cz.ps.Models", 1, 0, "Character");
}
