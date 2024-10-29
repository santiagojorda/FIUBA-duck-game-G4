#include "client.h"

#include <list>

Client::Client(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<Event*>& _queue_event, std::list<int>& _players_id) :
    skt(std::move(_skt)), 
    protocol(skt),
    receiver(_queue_event, protocol, _players_id),
    sender(_queue_gamestate, protocol)
    {   

    // protocol.receive();
    /*
    // rec -> te da la cantidad de ids , despues game te los comparte
    /
    */

}
