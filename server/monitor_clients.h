#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>

#include "client.h"
#include "monitor.h"


class MonitorClients: public Monitor<Client> {
private:
    // uint8_t count_players;
public:
    MonitorClients();
    // virtual void broadcast() = 0;
    Client new_item() override;
    void add_item(Client& client) override;
    void delete_item(Client& client) override;
    void shutdown() override;
    ~MonitorClients();
};

#endif