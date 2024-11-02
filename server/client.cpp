#include "client.h"

#include <list>

Client::Client(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<EventPlayer*>& _queue_event,
               ListPlayersID& _players_id):
        skt(std::move(_skt)),
        protocol(skt),
        receiver(_queue_event, protocol, _players_id),
        sender(_queue_gamestate, protocol) {
        
        receiver.start();
        sender.start();
}

void Client::send_gamestate(const GameState_t& game_state){
    sender.send(game_state);
}

bool Client::is_alive() { return receiver.is_alive() && sender.is_alive(); }

void Client::shutdown() {
    skt.shutdown(2);
    skt.close();
}
