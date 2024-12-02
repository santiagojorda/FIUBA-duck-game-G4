#include "monitor_clients.h"

MonitorClients::MonitorClients() {}
MonitorClients::~MonitorClients() {}

void MonitorClients::broadcast(GameState_t gamestate) {
    std::lock_guard<std::mutex> lock(mtx);

    for (Client& client: list) {
        client.send_gamestate(gamestate);
    }
}

bool MonitorClients::they_are_alive() {
    std::lock_guard<std::mutex> lock(mtx);
    int alive_count = 0;
    for (Client& client: list) {
        alive_count += client.is_alive();
    }
    return (alive_count != 0);
}


void MonitorClients::shutdown() {}

void MonitorClients::delete_item(Client& client) {
    std::lock_guard<std::mutex> lock(mtx);
    if (client.is_alive()) {
        client.shutdown();
    }
}