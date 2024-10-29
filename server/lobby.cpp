#include "lobby.h"

#include "acceptor_clients.h"

#define MAX_EVENTS_QUEUE 100

Lobby::Lobby():
        monitor_clients(),
        players_id(),
        queue_event(MAX_EVENTS_QUEUE),
        queue_gamestate(),
        game(players_id, monitor_clients, queue_event, queue_gamestate) {}

void Lobby::run(){
    AcceptorClients acceptor_clients(monitor_clients, queue_gamestate, queue_event, players_id);
    acceptor_clients.run();
    game.run();
    
    game.join();
    acceptor_clients.join();
}

// void Lobby::init_player_list(){
//     for(int i = 0; i < players_id.size(); i++){
//         players_id.push_back(i);
//     }
// }

// void Lobby::init_monitor_client(){

//     for(int i = 0; i < count_players; i++){
//         monitor_clients.add_item();;
//     }
// }

Lobby::~Lobby() {}