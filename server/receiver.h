#ifndef RECEIVER_H
#define RECEIVER_H

#include "../common/queue.h"
#include "../common/thread.h"

#include "event.h"
#include "game_state.h"
#include "protocol_server.h"

class Receiver: public Thread {
private:
    Queue<Event*>& queue;
    ProtocolServer& protocol;

public:
    explicit Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol);

    // capura los eventos del cliente y los manda al Game
    void run() override;

    // detiene la ejeucion del reciver (no cierra todo)
    void stop() override;
};

#endif