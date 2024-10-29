#include "receiver.h"


Receiver::Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol, std::list<int>& _players_id):
        queue(_queue), protocol(_protocol), players_id(_players_id) {}


void Receiver::run() {  
    while (this->_keep_running) {
        Event* event;
        // this->protocol.reciver_evert(evect); //construyo el evento con los IDs 0 ,1 ,2 .....
        // mando
        this->queue.push(event);
    }
}


void Receiver::stop() { Thread::stop(); }
