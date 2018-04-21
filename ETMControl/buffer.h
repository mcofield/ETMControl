#ifndef BUFFER_H
#define BUFFER_H

#include <QObject>
#include <QQueue>
#include "communication.h"

class Buffer: public QObject {
    Q_OBJECT
public:
    Buffer();
    QQueue<uint8_t> queue;
    CommPacket fetchPacket();
public:
    void receivePacket();
};

#endif // BUFFER_H
