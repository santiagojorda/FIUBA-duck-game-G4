#include "acceptor_clients.h"

#include "monitor_clients.h"
#include "client.h"
#include "protocol_server.h"
#include <list>

#define SERVNAME "8080"

AcceptorClients::AcceptorClients(MonitorClients& _monitor, Queue<GameState_t>& _queue_gamestate, Queue<Event*>& _queue_event, std::list<int>& _players_id) : 
    skt(SERVNAME),
    monitor(_monitor),
    queue_gamestate(_queue_gamestate),
    queue_event(_queue_event),
    players_id(_players_id)
    {
        run();
    }

void AcceptorClients::listen_new_client(){
    Socket new_skt = skt.accept();

    ProtocolServer protocol(new_skt);
    uint8_t count_players = protocol.receive_count_players();
    
    std::list<int> player_client_id;

    for (int i = 0; i < count_players; i++){
        int id = players_id.size();
        players_id.emplace_back(id);
        player_client_id.emplace_back(id);
    }
    

    // posible monitor de ids
    Client new_client(std::move(new_skt), queue_gamestate, queue_event, player_client_id);
    monitor.add_item(new_client);

    // Client client(new_skt, queue_gamestate, queue_event); // enviar las dos colas
}

void AcceptorClients::run(){
    try{
        // while(_keep_is_running){
        listen_new_client();
        // }
    }
    catch (...){

    }
}

void AcceptorClients::stop(){
    
    Thread::stop;
}