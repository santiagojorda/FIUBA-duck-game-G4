#ifndef MONITOR_GAMES_H
#define MONITOR_GAMES_H

#include <mutex>

#include "game.h"
#include "monitor.h"

class MonitorGame: public Monitor<Game> {
private:
public:
    MonitorGame();
    // virtual void broadcast() = 0;
    Game new_item() override;
    void add_item(Game& client) override;
    void delete_item(Game& client) override;
    void shutdown() override;
};

#endif