#include "receiver.h"

#include "event_factory.h"

Receiver::Receiver(Queue<EventPlayer*>& _queue, ProtocolServer& _protocol, ListPlayersID& _players_id):
        queue(_queue), protocol(_protocol), players_id(_players_id) {}

void Receiver::init_factories(){
    for (uint8_t& player_id : players_id){
        this->factories.push_back(EventFactory(player_id));   
    }
}

void Receiver::push_event(uint8_t& _player_id, uint8_t& _event_id) {
    if(_player_id < factories.size()){
        EventPlayer* event = factories[_player_id].get_event(_event_id);
        if(event){
            this->queue.push(event);
        }
    }
}

void Receiver::run() {

    try{
        uint8_t player_id, event_id;
        this->init_factories();
        while (this->_keep_running) {
            player_id = 0;
            event_id = 0;
            this->protocol.receive_event(player_id, event_id);
            this->push_event(player_id, event_id);
        }

    } catch (const std::exception& e) {
        std::cerr << "Receiver: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "error en el sender" << '\n';
    }
    stop();
}


void Receiver::stop() { Thread::stop(); }
