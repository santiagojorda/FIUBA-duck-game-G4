#ifndef CLIENT_RECEIVER_H
#define CLIENT_RECEIVER_H

#include "../common/queue.h"
#include "../common/thread.h"
#include "protocol/protocol_client.h"

#include "player_position.h"

class ClientReceiver: public Thread {
private:
    ClientProtocol& protocol;
    // El client es el dueño de la queue
    Queue<std::vector<PlayerPosition_t>>& positions;

public:
    /*
     * Constructor.
     */
    ClientReceiver(ClientProtocol& protocol, Queue<std::vector<PlayerPosition_t>>& positions);

    virtual void run() override;

    virtual ~ClientReceiver();

    // void receiver_data(std::vector<Coordinate>& coordenadas);
};

#endif  // CLIENT_RECEIVER_H
