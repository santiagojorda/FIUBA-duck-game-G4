#ifndef GAME_H
#define GAME_H

#include <list>

#include "../common/thread.h"

// #include "camera.h"
#include "event_player.h"
#include "game_logic.h"
#include "game_state.h"
#include "list_players.h"
#include "list_players_id.h"
#include "monitor_clients.h"
#include "player.h"

class Game: public Thread {
private:
    ListPlayers players;
    GameLogic game_logic;
    MonitorClients& monitor_client;
    Queue<EventPlayer*>& queue_event;  //<- para charalar
    Queue<GameState_t>& queue_gamestate;

    void sleep();
    void execute_new_events();
    void broadcast_gamestate();
    GameState_t get_gamestate();
    auto get_actual_milliseconds();

public:
    Game(ListPlayers& _players, MonitorClients& _monitor_client, Queue<EventPlayer*>& _queue_event,
         Queue<GameState_t>& _queue_gamestate);
    void run() override;
    void stop() override;
    ~Game();
};

#endif
