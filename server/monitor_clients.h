#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>

#include "client.h"
#include "monitor.h"

#include "event_player.h"
#include "list_players_id.h"

class MonitorClients{
private:

    std::list<Client> list;
    std::mutex mtx;
    
public:
    MonitorClients();
    void add_item(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<EventPlayer*>& _queue_event,
           ListPlayersID& _players_id);
    void delete_item(Client& client);
    void shutdown();
    void broadcast(GameState_t gamestate);
    ~MonitorClients();
};

#endif