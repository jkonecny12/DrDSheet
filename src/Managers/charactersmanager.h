#ifndef CHARACTERSMANAGER_H
#define CHARACTERSMANAGER_H

#include <QObject>
#include <QScopedPointer>

class CharactersModel;

class CharactersManagerPrivate;
class CharactersManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(CharactersModel* model READ model NOTIFY modelChanged)
public:
    virtual ~CharactersManager();

    static CharactersManager *instance();
    static void dropInstance();

    CharactersModel *model() const;

signals:
    void modelChanged();

public slots:

private:
    explicit CharactersManager(QObject *parent = 0);

    QScopedPointer<CharactersManagerPrivate> d_ptr;
    Q_DECLARE_PRIVATE(CharactersManager)

};

#endif // CHARACTERSMANAGER_H
