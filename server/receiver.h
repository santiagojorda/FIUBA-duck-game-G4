#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include "../common/queue.h"
#include "../common/thread.h"

#include "event.h"
#include "game_state.h"
#include "protocol_server.h"


class Receiver: public Thread {
private:
    std::vector<int>& ids_players;  // <- tiene que venir del CLient
    Queue<Event*>& queue;
    ProtocolServer& protocol;

public:
    explicit Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol);

    // PROPONGO QUE CUANDO INICE SE LE PASEN LOS  Y LOS IDS
    // explicit Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol);

    // capura los eventos del cliente y los manda al Game
    void run() override;

    // detiene la ejeucion del reciver (no cierra todo)
    void stop() override;
};

#endif