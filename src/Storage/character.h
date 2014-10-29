#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QScopedPointer>

class CharacterPrivate;
class QJsonObject;
class Character : public QObject
{
    Q_OBJECT

    Q_ENUMS(Class Race Sex)

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(Race race READ race WRITE setRace NOTIFY raceChanged)
    Q_PROPERTY(Sex sex READ sex WRITE setSex NOTIFY sexChanged)
    Q_PROPERTY(Class charClass READ charClass WRITE setCharClass NOTIFY charClassChanged)

public:

    enum class Class : short
    {
        Unknown,
        Warrior,
        Mage,
        Druid,
        Theurg,
        Thief,
        Hunter
    };

    enum class Race : short
    {
        Unknown,
        Human,
        Dwarf,
        Elf,
        Hobbit,
        Kroll
    };

    enum class Sex : short
    {
        Unknown,
        Male,
        Female
    };

    explicit Character(QObject *parent = 0);
    explicit Character(QString name, Race race, Sex sex, Class char_class, QObject *parent = 0);

    virtual ~Character();

    QString name() const;
    void setName(const QString name);

    Race race() const;
    void setRace(Race race);

    Sex sex() const;
    void setSex(Sex sex);

    Class charClass() const;
    void setCharClass(Class charClass);

    /** translators **/
    Q_INVOKABLE QString raceToString(Race race);
    Q_INVOKABLE QString sexToString(Sex sex);
    Q_INVOKABLE QString classToString(Class charClass);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

signals:
    void nameChanged();
    void raceChanged();
    void sexChanged();
    void charClassChanged();

public slots:

private:
    QScopedPointer<CharacterPrivate> d_ptr;
    Q_DECLARE_PRIVATE(Character)

};

#endif // CHARACTER_H
