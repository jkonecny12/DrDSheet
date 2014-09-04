#include "character.h"

/*** PIMPL ***/

class CharacterPrivate {
public:
    QString m_name = QString();
    Character::Race m_race = Character::Race::Unknown;
    Character::Sex m_sex = Character::Sex::Unknown;
    Character::Class m_char_class = Character::Class::Unknown;
};


/*** MAIN ***/

Character::Character(QObject *parent) :
    QObject(parent),
    d_ptr(new CharacterPrivate())
{
}

Character::Character(QString name, Character::Race race,
                     Character::Sex sex, Character::Class char_class,
                     QObject *parent) :
    QObject(parent),
    d_ptr(new CharacterPrivate())
{
    Q_D(Character);

    d->m_name = name;
    d->m_race = race;
    d->m_sex = sex;
    d->m_char_class = char_class;
}

Character::~Character()
{
}

QString Character::name() const
{
    Q_D(const Character);

    return d->m_name;
}

void Character::setName(const QString name)
{
    Q_D(Character);

    if(d->m_name != name)
        Q_EMIT this->nameChanged();

    d->m_name = name;
}

Character::Race Character::race() const
{
    Q_D(const Character);

    return d->m_race;
}

void Character::setRace(Character::Race race)
{
    Q_D(Character);

    if(d->m_race != race)
        Q_EMIT this->raceChanged();

    d->m_race = race;
}

Character::Sex Character::sex() const
{
    Q_D(const Character);

    return d->m_sex;
}

void Character::setSex(Character::Sex sex)
{
    Q_D(Character);

    if(d->m_sex != sex)
        Q_EMIT this->sexChanged();

    d->m_sex = sex;
}

Character::Class Character::charClass() const
{
    Q_D(const Character);

    return d->m_char_class;
}

void Character::setCharClass(Character::Class charClass)
{
    Q_D(Character);

    if(d->m_char_class != charClass)
        Q_EMIT this->charClassChanged();

    d->m_char_class = charClass;
}

QString Character::raceToString(Character::Race race)
{
    QString ret;

    switch(race)
    {
    case Race::Dwarf:
        ret = tr("Trpaslík");
        break;
    case Race::Elf:
        ret = tr("Elf");
        break;
    case Race::Hobbit:
        ret = tr("Hobit");
        break;
    case Race::Human:
        ret = tr("Člověk");
        break;
    case Race::Kroll:
        ret = tr("Kroll");
        break;
    default:
        ret = tr("Neznámý");
        break;
    }

    return ret;
}

QString Character::sexToString(Character::Sex sex)
{
    QString ret;

    switch(sex)
    {
    case Sex::Female:
        ret = tr("Žena");
        break;
    case Sex::Male:
        ret = tr("Muž");
        break;
    default:
        ret = tr("Neznámí");
        break;
    }

    return ret;
}

QString Character::classToString(Character::Class charClass)
{
    QString ret;

    switch(charClass)
    {
    case Class::Druid:
        ret = tr("Druid");
        break;
    case Class::Hunter:
        ret = tr("Hraničář");
        break;
    case Class::Mage:
        ret = tr("Mág");
        break;
    case Class::Theurg:
        ret = tr("Theurg");
        break;
    case Class::Thief:
        ret = tr("Thief");
        break;
    case Class::Warrior:
        ret = tr("Válečník");
        break;
    default:
        ret = tr("Neznámý");
    }

    return ret;
}
