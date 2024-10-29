#include "client.h"


Client::Client(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<Event*>& _queue_event) :
    skt(std::move(_skt)), 
    protocol(skt),
    receiver(_queue_event, protocol),
    sender(_queue_gamestate, protocol)
    {   

    // protocol.receive();
    /*
    // rec -> te da la cantidad de ids , despues game te los comparte
    /
    */

}
