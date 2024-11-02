#include "acceptor_clients.h"

#include <list>

#include "client.h"
#include <iostream>
#include "monitor_clients.h"
#include "protocol_server.h"

#define SERVNAME "8080"

AcceptorClients::AcceptorClients(MonitorClients& _monitor, Queue<GameState_t>& _queue_gamestate,
                                 Queue<EventPlayer*>& _queue_event, ListPlayersID& _players_id):
        Acceptor(SERVNAME),
        monitor(_monitor),
        queue_gamestate(_queue_gamestate),
        queue_event(_queue_event),
        players_id(_players_id) {}

void AcceptorClients::listen_new_client() {
    Socket new_skt = skt.accept();

    ProtocolServer protocol(new_skt);

    // chequear si se envia un dummy para inicializar el game y cortar el acceptor

    uint8_t count_players = protocol.receive_count_players();

    ListPlayersID client_players_id;

    for (uint8_t i = 0; i < count_players; i++) {
        uint8_t id = players_id.size();
        players_id.emplace_back(id);
        client_players_id.emplace_back(id);
    }   

    monitor.add_item(std::move(new_skt), queue_gamestate, queue_event, client_players_id);

}

void AcceptorClients::run() {
    try {
        // while(_keep_running){
        listen_new_client();
        // }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    } catch (...) {
        std::cerr << "error en el acceptor client" << '\n';
    }
    stop();
}

void AcceptorClients::stop() { Thread::stop(); }

AcceptorClients::~AcceptorClients() { Acceptor::~Acceptor(); }
