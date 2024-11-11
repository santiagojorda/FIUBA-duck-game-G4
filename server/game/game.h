#ifndef GAME_H
#define GAME_H

#include <list>

#include "../../common/thread.h"
#include "../client/monitor_clients.h"
#include "../events/queue_event_player.h"
#include "../map/map.h"
#include "../player/list_players.h"

#include "game_logic.h"
#include "queue_game_state.h"

class Game: public Thread {
private:
    ListPlayers players;
    Map map;
    GameLogic game_logic;
    MonitorClients& monitor_client;
    QueueEventPlayer& queue_event;  //<- para charalar
    QueueGameState& queue_gamestate;

    void sleep();
    void execute_new_events();
    void broadcast_gamestate();
    GameState_t get_gamestate();
    auto get_actual_milliseconds();
    void update_states();

public:
    Game(ListPlayers& _players, MonitorClients& _monitor_client, QueueEventPlayer& _queue_event,
         QueueGameState& _queue_gamestate);
    void run() override;
    void stop() override;
    ~Game();
};

#endif
