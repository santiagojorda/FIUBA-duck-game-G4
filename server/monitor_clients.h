#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>

#include "client.h"
#include "monitor.h"

#include "event_player.h"

class MonitorClients{
private:

    std::list<Client> list;
    std::mutex mtx;
    // uint8_t count_players;

public:
    MonitorClients();
    // virtual void broadcast() = 0;
    // Client new_item() override;
    // void add_item(Client& client);
    void add_item(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<EventPlayer*>& _queue_event,
           std::list<int>& _players_id);
    void delete_item(Client& client);
    void shutdown();
    void broadcast(GameState_t gamestate);
    ~MonitorClients();
};

#endif