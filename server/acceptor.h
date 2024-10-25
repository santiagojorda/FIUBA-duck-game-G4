#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "../common/socket.h"
#include "../common/thread.h"

class Acceptor: public Thread {
private:
    Socket skt;

public:
    Acceptor();
    virtual void run() = 0;
    virtual void stop() = 0;
};

#endif
