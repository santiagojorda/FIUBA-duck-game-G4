#include "receiver.h"

#include "event_factory.h"

Receiver::Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol, std::list<int>& _players_id):
        queue(_queue), protocol(_protocol), players_id(_players_id) {}


void Receiver::run() {
    EventFactory factory;
    while (this->_keep_running) {
        uint8_t id_player, id_event = 0;
        this->protocol.receive_event(id_player, id_event);
        this->queue.push(factory.get_event(id_player));
    }
}


void Receiver::stop() { Thread::stop(); }
