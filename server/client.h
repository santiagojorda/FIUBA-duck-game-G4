#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "event_player.h"
#include "list_players_id.h"
#include "receiver.h"
#include "sender.h"

#include "queue_event_player.h"
#include "queue_game_state.h"

class Client {
private:
    Socket skt;
    ProtocolServer protocol;
    Receiver receiver;
    Sender sender;

public:
    Client(Socket&& _skt, QueueGameState& _queue_gamestate, QueueEventPlayer& _queue_event,
           ListPlayersID& _players_id);
    void shutdown();
    void send_gamestate(const GameState_t& game_state);
    bool is_alive();
};

#endif
