#ifndef SHAREDRESSTHON_H
#define SHAREDRESSTHON_H

#include <QObject>
#include <QMutex>

class SharedResSthon : public QObject
{
    Q_OBJECT

public:
    static SharedResSthon *getInstance();
    bool changeOSCounter(int addition);

    int getOpenSocketsCounter() const;

private:
    SharedResSthon();
    static SharedResSthon* instance;
    SharedResSthon(const SharedResSthon&);
    const SharedResSthon& operator=(const SharedResSthon&);

    int openSocketsCounter;

signals:
    void updateSocketCounter();

public slots:
};

#endif // SHAREDRESSTHON_H
