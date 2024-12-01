#ifndef GAME_H
#define GAME_H

#include <list>

#include "../../common/thread.h"
#include "../client/monitor_clients.h"
#include "../events/queue_events.h"
#include "../map/map.h"
#include "../player/list_players.h"

#include "game_logic.h"
#include "queue_game_state.h"
#include "initial_values.h"


class Game: public Thread {
private:
    ListPlayers& players;
    Map map;
    ListProjectiles map_projectiles;
    GameLogic game_logic;
    MonitorClients& monitor_client;
    QueueEvents& queue_events;  //<- para charalar
    QueueGameState& queue_gamestate;
    inical_values_t inicial_values;

    void load_map();

    void reset_values();
    
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
