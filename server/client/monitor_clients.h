#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>

#include "client.h"
#include "../events/event_player.h"
#include "../player/list_players_id.h"
#include "../events/queue_event_player.h"
#include "../game/queue_game_state.h"

class MonitorClients {
private:
    // cppcheck-suppress unusedStructMember
    std::list<Client> list;
    // cppcheck-suppress unusedStructMember
    std::mutex mtx;

public:
    MonitorClients();

    // void add_item(Socket&& _skt, QueueGameState& _queue_gamestate, QueueEventPlayer&
    // _queue_event,
    //        ListPlayersID& _client_players_id);

    template <typename... Args>
    void add_item(Args&&... args) {
        std::lock_guard<std::mutex> lock(mtx);
        list.emplace_back(std::forward<Args>(args)...);
    }

    void delete_item(Client& client);
    void shutdown();
    void broadcast(GameState_t gamestate);
    ~MonitorClients();
};

#endif