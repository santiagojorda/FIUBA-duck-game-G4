#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "receiver.h"
#include "sender.h"

class Client {
private:
    Socket skt;
    ProtocolServer protocol;
    Receiver receiver;
    Sender sender;
    // std::vector<int> players_id;

public:
    Client(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<Event*>& _queue_event,
           std::list<int>& _players_id);
    void shutdown();
    bool is_alive();
};

#endif
