#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>
#include "defines.h"

typedef struct CommPacket{
    uint8_t type;
    uint8_t command;
    uint8_t length;
    uint8_t data[sizeof(int)];
} commPacket;

CommPacket buildPacket(uint8_t typ,uint8_t com, uint8_t len, uint8_t dat);
bool sendPacket(CommPacket message);
CommPacket receivePacket();

#endif // COMMUNICATION_H
