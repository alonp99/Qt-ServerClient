#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QString>

struct payload {
  quint32 color;
  /*unsigned*/ char* sender;
  /*unsigned*/ char* text;
};

class cMessage
{

public:
    cMessage();
        enum msgType {QUICK,REGULAR};

        int senderID;

        QString data;


};

#endif // CMESSAGE_H
