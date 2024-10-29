#include "acceptor_game.h"

#include "protocol_server.h"

AcceptorGame::AcceptorGame(const std::string& _servname) : skt(_servname.c_str()) {}

void AcceptorGame::listen_new_game(){
    Socket new_skt = skt.accept();

    ProtocolServer protocol(new_skt);
    uint8_t count_players = protocol.receive_count_players();

    Game game()

}

void AcceptorGame::run(){
    try{
        // while(true){

        // }

        listen_new_game();
    }
    catch (...){

    }
}

void Acceptor::stop(){
    skt.shutdown(2);
    skt.close();
}