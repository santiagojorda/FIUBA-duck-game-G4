#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "event_player.h"
#include "vector_player_id.h"
#include "queue_event_player.h"
#include "queue_game_state.h"
#include "receiver.h"
#include "sender.h"

class Client {
private:
    Socket skt;
    ProtocolServer protocol;
    Receiver receiver;
    Sender sender;

public:
    Client(Socket&& _skt, QueueGameState& _queue_gamestate, QueueEventPlayer& _queue_event,
           VectorPlayerID& _players_id);
    void shutdown();
    void send_gamestate(const GameState_t& game_state);
    bool is_alive();
};

#endif
