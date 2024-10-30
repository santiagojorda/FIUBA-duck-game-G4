#include "monitor_clients.h"

MonitorClients::MonitorClients(): Monitor<Client>() {}
MonitorClients::~MonitorClients() { Monitor::~Monitor(); }

void MonitorClients::add_item(Client& client) {
    int i = 0;
    if (client.is_alive()) {
        i++;
    }
}

void MonitorClients::shutdown() {}

void MonitorClients::delete_item(Client& client) {
    int i = 0;
    if (client.is_alive()) {
        i++;
    }
}