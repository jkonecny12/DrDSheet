#include "charactersmodel.h"

#include "../Storage/character.h"

/*** PIMPL ***/

class CharactersModelPrivate {
public:
    QList<Character *> m_characters;

    CharactersModelPrivate(CharactersModel *q)
    {
        m_characters.append(new Character("test", Character::Race::Elf,
                                          Character::Sex::Male,
                                          Character::Class::Druid,
                                          q
                                          )
                            );

        m_characters.append(new Character("test1", Character::Race::Human,
                                          Character::Sex::Male,
                                          Character::Class::Theurg,
                                          q
                                          )
                            );

        m_characters.append(new Character("test2", Character::Race::Dwarf,
                                          Character::Sex::Female,
                                          Character::Class::Thief,
                                          q
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

        Character *character = d->m_characters[index.row()];

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

    return d->m_characters[index];
}

void CharactersModel::removeCharacter(int index)
{
    Q_D(CharactersModel);

    this->removeRow(index);
}
