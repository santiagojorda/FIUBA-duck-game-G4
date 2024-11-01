#include "monitor_clients.h"

MonitorClients::MonitorClients()  {}
MonitorClients::~MonitorClients() {}

void MonitorClients::add_item(Socket&& _skt, Queue<GameState_t>& _queue_gamestate, Queue<EventPlayer*>& _queue_event,
           std::list<int>& _players_id) {
    std::lock_guard<std::mutex> lock(mtx);
    // Client client(std::move(_skt), _queue_gamestate, _queue_event, _players_id);
    // client.run();
    
    list.emplace_back(std::move(_skt), _queue_gamestate, _queue_event, _players_id);    
}

void MonitorClients::broadcast(GameState_t gamestate){
    std::lock_guard<std::mutex> lock(mtx);

    for (Client& client: list) {
        client.send_gamestate(gamestate);
    }
}

void MonitorClients::shutdown() {}

void MonitorClients::delete_item(Client& client) {
    std::lock_guard<std::mutex> lock(mtx);
    
    // porfavor borrar
    if(client.is_alive()){
        client.shutdown();
    }
}