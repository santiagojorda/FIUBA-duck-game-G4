#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include "../common/queue.h"
#include "../common/thread.h"

#include "event_player.h"
#include "game_state.h"
#include "list_players_id.h"
#include "protocol_server.h"
#include "event_factory.h"


class Receiver: public Thread {
private:
    Queue<EventPlayer*>& queue;
    ProtocolServer& protocol;
    ListPlayersID players_id;  // <- tiene que venir del CLient
    std::vector<EventFactory> factories;

    void init_factories();
    void push_event(uint8_t& _player_id, uint8_t& _event_id);


public: 
    explicit Receiver(Queue<EventPlayer*>& _queue, ProtocolServer& _protocol,
                      ListPlayersID& _players_id);

    // PROPONGO QUE CUANDO INICE SE LE PASEN LOS  Y LOS IDS
    // explicit Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol);


    // capura los eventos del cliente y los manda al Game
    void run() override;

    // detiene la ejeucion del reciver (no cierra todo)
    void stop() override;
};

#endif