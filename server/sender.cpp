#include "sender.h"


Sender::Sender(ProtocolServer& _protocol, Queue<GameState_t>& _queue):
        protocol(std::ref(_protocol)), queue(std::ref(_queue)), Thread() {}


void Sender::run() {
    try {
        while (this->_keep_running) {
            GameState_t actual_estate = this->queue.pop();
            // this->protocol send gameestate
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Sender::stop() { Thread::stop(); }
