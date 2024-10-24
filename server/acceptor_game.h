#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include "acceptor.h"
#include "../common/thread.h"
#include "../common/socket.h"

class AcceptorGame : public Acceptor {
private:
    Socket skt;

    void create_game();
    void listen_new_game();

public:
    AcceptorGame();
    void run() override;
    void stop() override;
};

#endif
