#include "sender.h"


Sender::Sender(Queue<GameState_t>& _queue, ProtocolServer& _protocol):
        queue(std::ref(_queue)), protocol(std::ref(_protocol)) {}


void Sender::run() {
    try {
        while (this->_keep_running) {
            GameState_t actual_estate = this->queue.pop();
            this->protocol.send_game_state(actual_estate);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Sender::send(GameState_t& game_state){
    queue.try_push(game_state);
}

void Sender::stop() { Thread::stop(); }

Sender::~Sender() {}
