#ifndef CLIENT_H
#define CLIENT_H

#include "receiver.h"
#include "sender.h"

class Client {
private:
    Receiver receiver;
    Sender sender;
    Socket skt;

public:
    Client(Socket&& skt);
    void shutdown();
    bool is_alive();
};

#endif
