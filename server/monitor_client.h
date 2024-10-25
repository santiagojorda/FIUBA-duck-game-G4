#ifndef MONITOR_CLIENT_H
#define MONITOR_CLIENT_H

#include <mutex>

#include "client.h"
#include "monitor.h"

class MonitorClient: public Monitor<Client> {
private:
public:
    MonitorClient();
    // virtual void broadcast() = 0;
    Client new_item() override;
    void add_item(Client& client) override;
    void delete_item(Client& client) override;
    void shutdown() override;
};

#endif