#include "sharedressthon.h"

SharedResSthon* SharedResSthon::instance = 0;

SharedResSthon* SharedResSthon::getInstance()
{
    QMutex mutex;
    mutex.lock();
    if(!instance) {
        instance = new SharedResSthon();
        instance->openSocketsCounter = 0;
        //return instance;
    }
    mutex.unlock();
    return instance;
}

bool SharedResSthon::changeOSCounter(int addition)
{
    if (addition!= 1 && addition != -1)
        return false;
    QMutex mutex;
    mutex.lock();
    openSocketsCounter += addition;
    mutex.unlock();
    emit updateSocketCounter();
    return true;
}

SharedResSthon::SharedResSthon(){}

int SharedResSthon::getOpenSocketsCounter() const
{
    return openSocketsCounter;
}



//SharedResSthon::SharedResSthon(const SharedResSthon &)
//{

//}

//const SharedResSthon &SharedResSthon::operator=(const SharedResSthon &)
//{

//}
