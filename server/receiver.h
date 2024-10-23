#ifndef RECEIVER_H
#define RECEIVER_H

#include "../common/queue.h"
#include "../common/thread.h"
#include "game_state.h"
#include "protocol_server.h"
#include "event.h"

class Receiver: public Thread {
private:
    Queue<Event*> queue;
    ProtocolServer& protocol;

public:
    explicit Receiver(ProtocolServer& protocol);
    void run() override;
    void stop() override;
};

#endif