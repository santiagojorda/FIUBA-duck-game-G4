#ifndef SERVER_SENDER_H_
#define SERVER_SENDER_H_

#include "../common/queue.h"
#include "../common/thread.h"

#include "game_state.h"
#include "protocol_server.h"

class Sender: public Thread {
private:
    Queue<GameState_t>& queue;
    ProtocolServer& protocol;

public:
    explicit Sender(ProtocolServer& _protocol, Queue<GameState_t>& _queue);
    void run() override;
    void stop() override;

    ~Sender();
};

#endif  // SERVER_SENDER_H_