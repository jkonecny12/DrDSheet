#include "drdsheetmain.h"

#include <QtQml>

#include "Storage/character.h"
#include "Models/charactersmodel.h"
#include "Managers/charactersmanager.h"

/*** SINGLETON GET FUNCS ***/
QObject *getCharactersManager(QQmlEngine *engine, QJSEngine *jsEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(jsEngine);

    return CharactersManager::instance();
}


/*** MAIN ***/

DrDSheetMain::DrDSheetMain(QObject *parent) :
    QObject(parent)
{
}

DrDSheetMain::~DrDSheetMain()
{

}

void DrDSheetMain::registerQml()
{
    /* singletons */
    qmlRegisterSingletonType<CharactersManager>("cz.ps.Managers", 1, 0,
                                                "CharactersManager",
                                                &getCharactersManager);

    qmlRegisterType<CharactersModel>("cz.ps.Models", 1, 0, "CharactersModel");
    qmlRegisterType<Character>("cz.ps.Models", 1, 0, "Character");
}

void DrDSheetMain::freeResources()
{
    CharactersManager::dropInstance();
}
