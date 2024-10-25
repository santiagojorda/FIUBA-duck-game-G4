#include "receiver.h"


Receiver::Receiver(Queue<Event*>& _queue, ProtocolServer& _protocol):
        queue(_queue), protocol(_protocol), Thread() {}


void Receiver::run() {
    while (this->_keep_running) {
        Event* event;
        // this->protocol.reciver_evert(evect); //construyo el evento con los IDs 0 ,1 ,2 .....
        // mando
        this->queue.push(event);
    }
}


void Receiver::stop() { Thread::stop(); }
