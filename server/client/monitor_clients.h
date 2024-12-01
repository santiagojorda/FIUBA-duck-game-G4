#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>
#include <iostream>

#include "../game/queue_game_state.h"
#include "../player/list_players_id.h"

#include "client.h"

class MonitorClients {
private:
    // cppcheck-suppress unusedStructMember
    std::list<Client> list;
    // cppcheck-suppress unusedStructMember
    std::mutex mtx;

public:
    MonitorClients();

    template <typename... Args>
    void add_item(Args&&... args) {
        std::lock_guard<std::mutex> lock(mtx);
        list.emplace_back(std::forward<Args>(args)...);
        std::cout << "client created" << std::endl;
    }
    
    bool they_are_alive();
    void delete_item(Client& client);
    void shutdown();
    void broadcast(GameState_t gamestate);
    ~MonitorClients();
};

#endif