#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include "../../common/queue.h"
#include "../../common/thread.h"

#include "../events/event_factory.h"
#include "../events/event_player.h"
#include "../game/game_state.h"
#include "../protocol/protocol_server.h"
#include "../player/vector_player_id.h"
#include "../events/queue_event_player.h"


class Receiver: public Thread {
private:
    QueueEventPlayer& queue;
    ProtocolServer& protocol;
    VectorPlayerID players_id;  // interna 0-1
    // cppcheck-suppress unusedStructMember
    std::vector<EventFactory> factories;

    void init_factories();
    void push_event(const uint8_t& _player_id, const uint8_t& _event_id);


public:
    explicit Receiver(QueueEventPlayer& _queue, ProtocolServer& _protocol,
                      VectorPlayerID& _players_id);

    void run() override;
};

#endif