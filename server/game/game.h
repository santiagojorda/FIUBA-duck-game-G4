#ifndef GAME_H
#define GAME_H

#include <list>

#include "../../common/thread.h"
#include "../client/monitor_clients.h"
#include "../events/queue_events.h"
#include "../weapons/list_guns.h"
#include "../map/map.h"
#include "../player/list_players.h"

#include "game_logic.h"
#include "queue_game_state.h"

class Game: public Thread {
private:
    ListPlayers& players;
    Map map;
    ListGuns map_guns;
    ListProjectiles map_projectiles;
    GameLogic game_logic;
    MonitorClients& monitor_client;
    QueueEvents& queue_events;  //<- para charalar
    QueueGameState& queue_gamestate;

    void load_map();

    void execute_new_events();
    void broadcast_gamestate();
    GameState_t get_gamestate();

public:
    Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEvents& _queue_events,
         QueueGameState& _queue_gamestate);
    void run() override;
    void stop() override;
    ~Game();
};

#endif
