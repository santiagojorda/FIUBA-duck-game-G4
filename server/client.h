#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "receiver.h"
#include "sender.h"

class Client {
private:
    Socket skt;
    Receiver receiver;
    Sender sender;
    std::vector<int> ids_players;

public:
    Client(Socket&& _skt);
    void shutdown();
    bool is_alive();
};

#endif
