#ifndef SENDER_H
#define SENDER_H

#include "../common/queue.h"
#include "../common/thread.h"
#include "game_state.h"
#include "protocol_server.h"

class Sender: public Thread {
private:
    Queue<GameState_t>& queue;

    ProtocolServer& protocol;

public:
    explicit Sender(ProtocolServer& protocol);
    void run() override;
    void stop() override;
};

#endif