#include "acceptor_game.h"
#include "monitor_games.h"

AcceptorGame::AcceptorGame(const std::string& servname, MonitorGames& monitor_games) : skt(servname.c_str()) {} 

void AcceptorGame::listen_new_game(){
    Socket skt_new_game = skt.accept();
    Game* new_game = new Game();
    game_list.push_back(new_game);
}

void AcceptorGame::run(){
    try{
        while(_keep_running){
            listen_new_game();
        }
    } catch (...) {
        stop();
    }
}S

void AcceptorGame::stop(){
    if(_keep_running){
        Thread::stop();
        skt.shutdown(2);
        skt.close();
    }
}