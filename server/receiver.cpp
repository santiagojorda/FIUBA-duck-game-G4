#include "receiver.h"

#include "event_factory.h"

Receiver::Receiver(Queue<EventPlayer*>& _queue, ProtocolServer& _protocol,
                   VectorPlayerID& _players_id):
        queue(_queue), protocol(_protocol), players_id(_players_id) {}

void Receiver::init_factories() {
    for (uint8_t& player_id: players_id) {
        this->factories.push_back(EventFactory(player_id));
    }
}

void Receiver::push_event(const uint8_t& _player_id, const uint8_t& _event_id) {
    if (_player_id < factories.size()) {
        EventPlayer* event = factories[_player_id].get_event(_event_id);
        if (event) {
            this->queue.push(event);
        }
    }
}

void Receiver::run() {

    try {
        this->init_factories();
        while (this->_keep_running) {
            uint8_t player_id = 0;
            uint8_t event_id = 0;
            this->protocol.receive_event(player_id, event_id);

            // buscar en la lista
            // players_id.begin()
            this->push_event(players_id[player_id], event_id);
        }

    } catch (const std::exception& e) {
        std::cerr << "Receiver: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "error en el sender" << '\n';
    }
    stop();
}
