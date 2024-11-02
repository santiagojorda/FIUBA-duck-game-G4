#ifndef ACCEPTOR_GAME_H
#define ACCEPTOR_GAME_H

#include <string>

#include "../common/socket.h"
#include "../common/thread.h"

#include "acceptor.h"

class AcceptorGame: public Acceptor {
private:
    void create_game();
    void listen_new_game();

public:
    explicit AcceptorGame(const std::string& _servname);
    void run() override;
    void stop() override;
    virtual ~AcceptorGame();
};

#endif  // ACCEPTOR_GAME_H
