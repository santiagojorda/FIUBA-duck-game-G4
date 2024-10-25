#ifndef GAME_H
#define GAME_H

#include <list>

#include "../common/thread.h"

#include "camera.h"
#include "game_logic.h"
#include "game_state.h"
#include "monitor_clients.h"
#include "player.h"

class Game: public Thread {
private:
    GameLogic game_logic;
    Queue<GameState_t> queue;
    MonitorClients& monitor_client;
    std::list<Player> players;

public:
    Game();
    void run() override;
    void stop() override;
};

#endif
