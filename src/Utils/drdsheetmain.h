#ifndef DRDSHEETMAIN_H
#define DRDSHEETMAIN_H

#include <QObject>

class DrDSheetMain : public QObject
{
    Q_OBJECT

public:
    DrDSheetMain(QObject *parent = 0);

    virtual ~DrDSheetMain();

    void registerQml();

public slots:
    void freeResources();
};

#endif // DRDSHEETMAIN_H
