#include "drdsheetmain.h"

#include <QtQml>

#include "../Storage/character.h"
#include "../Models/charactersmodel.h"
#include "../Managers/charactersmanager.h"

DrDSheetMain::DrDSheetMain(QObject *parent) :
    QObject(parent)
{
}

DrDSheetMain::~DrDSheetMain()
{

}

void DrDSheetMain::registerQml()
{
    qmlRegisterType<CharactersModel>("cz.ps.Models", 1, 0, "CharactersModel");
    qmlRegisterType<Character>("cz.ps.Models", 1, 0, "Character");
}

void DrDSheetMain::freeResources()
{
    CharactersManager::dropInstance();
}
