#include "charactersmodel.h"

#include "../Storage/character.h"

#include <QSharedPointer>
#include <QJsonObject>
#include <QJsonArray>

/*** CONSTANTS ***/

#define JS_CHARACTERS "characters"

/*** PIMPL ***/

class CharactersModelPrivate {
public:
    QList<QSharedPointer<Character> > m_characters;

    CharactersModelPrivate(CharactersModel *q)
    {
        m_characters.append(QSharedPointer<Character>(
                                new Character("test", Character::Race::Elf,
                                              Character::Sex::Male,
                                              Character::Class::Druid,
                                              q
                                              )
                                )
                            );

        m_characters.append(QSharedPointer<Character>(
                                new Character("test1", Character::Race::Human,
                                              Character::Sex::Male,
                                              Character::Class::Theurg,
                                              q
                                              )
                                )
                            );

        m_characters.append(QSharedPointer<Character>(
                                new Character("test2", Character::Race::Dwarf,
                                              Character::Sex::Female,
                                              Character::Class::Thief,
                                              q
                                              )
                                )
                            );
    }
};

/*** MAIN ***/

CharactersModel::CharactersModel(QObject *parent) :
    QAbstractListModel(parent),
    d_ptr(new CharactersModelPrivate(this))
{
}

CharactersModel::~CharactersModel()
{

}

int CharactersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    Q_D(const CharactersModel);

    return d->m_characters.count();
}

QVariant CharactersModel::data(const QModelIndex &index, int role) const
{
    Q_D(const CharactersModel);

    if(index.isValid())
    {
        if(d->m_characters.count() <= index.row())
            return QVariant();

        QSharedPointer<Character> character = d->m_characters[index.row()];

        switch(role)
        {
        case Roles::name:
            return QVariant(character->name());
        case Roles::race:
            return QVariant(static_cast<int>(character->race()));
        case Roles::sex:
            return QVariant(static_cast<int>(character->sex()));
        case Roles::characterClass:
            return QVariant(static_cast<int>(character->charClass()));
        }
    }

    return QVariant();
}

QHash<int, QByteArray> CharactersModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Roles::name] = "name";
    roles[Roles::race] = "race";
    roles[Roles::sex] = "sex";
    roles[Roles::characterClass] = "characterClass";

    return roles;
}

bool CharactersModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_D(CharactersModel);

    if(d->m_characters.count() <= (row + count))
        return false;

    beginRemoveRows(parent, row, row + count);

    for(unsigned short i = 0; i < count; i++)
    {
        d->m_characters.removeAt(row);
    }

    endRemoveRows();

    return true;
}

Character *CharactersModel::getCharacter(int index)
{
    Q_D(CharactersModel);

    return d->m_characters[index].data();
}

void CharactersModel::read(const QJsonObject &json)
{
    Q_D(CharactersModel);

    d->m_characters.clear();

    QJsonArray jsArray = json[JS_CHARACTERS].toArray();

    for(int i = 0; i < jsArray.count(); i++)
    {
        QJsonObject js_char = jsArray.at(i).toObject();
        QSharedPointer<Character> character(new Character());
        character->read(js_char);
        d->m_characters.append(character);
    }
}

void CharactersModel::write(QJsonObject &json) const
{
    Q_D(const CharactersModel);

    QJsonArray jsCharArray;

    foreach(auto character, d->m_characters)
    {
        QJsonObject jsChar;
        character->write(jsChar);

        jsCharArray.append(jsChar);
    }

    json[JS_CHARACTERS] = jsCharArray;
}

void CharactersModel::removeCharacter(int index)
{
    this->removeRow(index);
}
