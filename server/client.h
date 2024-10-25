#ifndef CLIENT_H
#define CLIENT_H

#include "receiver.h"
#include "sender.h"

class Client {
private:
    Socket skt;
    Receiver receiver;
    Sender sender;

public:
    Client(Socket&& _skt);
    void shutdown();
    bool is_alive();
};

#endif
