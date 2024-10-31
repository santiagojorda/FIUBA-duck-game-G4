#include "monitor_clients.h"

MonitorClients::MonitorClients(): Monitor<Client>() {}
MonitorClients::~MonitorClients() { Monitor::~Monitor(); }

void MonitorClients::add_item(Client& client) {
    // cambiar
    int i = 0;
    if (client.is_alive()) {
        i++;
    }
}

void MonitorClients::broadcast(GameState_t gamestate){
    std::unique_lock<std::mutex> lock(mtx);

    for (Client& client: list) {
        client.send_gamestate(gamestate);
    }
}

void MonitorClients::shutdown() {}

void MonitorClients::delete_item(Client& client) {
    // cambiar
    int i = 0;
    if (client.is_alive()) {
        i++;
    }
}