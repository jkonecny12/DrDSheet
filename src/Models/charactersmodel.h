#ifndef CHARACTERSMODEL_H
#define CHARACTERSMODEL_H

#include <QAbstractListModel>
#include <QScopedPointer>

class Character;

class CharactersModelPrivate;
class CharactersModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles
    {
        name = Qt::UserRole + 1,
        race,
        sex,
        characterClass
    };

    explicit CharactersModel(QObject *parent = 0);

    virtual ~CharactersModel();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE Character *getCharacter(int index);

private:
    QScopedPointer<CharactersModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(CharactersModel)
};

#endif // CHARACTERSMODEL_H
