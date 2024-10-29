#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "../common/socket.h"
#include "../common/thread.h"

class Acceptor: public Thread {
protected:
    Socket skt;

public:
    Acceptor(const std::string& _servname);
    virtual void run() override = 0;
    virtual void stop() override = 0;
    virtual ~Acceptor();
};

#endif
