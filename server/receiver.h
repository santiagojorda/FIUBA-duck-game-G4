#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include "../common/queue.h"
#include "../common/thread.h"

#include "event_factory.h"
#include "event_player.h"
#include "game_state.h"
#include "list_players_id.h"
#include "protocol_server.h"


class Receiver: public Thread {
private:
    Queue<EventPlayer*>& queue;
    ProtocolServer& protocol;
    ListPlayersID players_id;
    // cppcheck-suppress unusedStructMember
    std::vector<EventFactory> factories;

    void init_factories();
    void push_event(const uint8_t& _player_id, const uint8_t& _event_id);


public:
    explicit Receiver(Queue<EventPlayer*>& _queue, ProtocolServer& _protocol,
                      ListPlayersID& _players_id);

    void run() override;
};

#endif