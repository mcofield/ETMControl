#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>
#include "defines.h"
#include <QObject>

class CommPacket : QObject{
    Q_OBJECT
public:
    uint8_t type;
    uint8_t command;
    uint8_t length;
    uint8_t data;
    CommPacket (uint8_t typ,uint8_t com, uint8_t len, uint8_t dat);
    void sendPacket();
};



#endif // COMMUNICATION_H
