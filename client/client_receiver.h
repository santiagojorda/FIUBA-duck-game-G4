#ifndef CLIENT_RECEIVER_H
#define CLIENT_RECEIVER_H

#include "../common/queue.h"
#include "../common/thread.h"

#include "protocol_client.h"

class ClientReceiver: public Thread {
private:
    ClientProtocol& protocol;
    // El client es el dueño de la queue
    Queue<std::vector<Coordinate>>& positions;

public:
    /*
     * Constructor.
     */
    ClientReceiver(ClientProtocol& protocol, Queue<std::vector<Coordinate>>& positions);

    virtual void run() override;

    virtual ~ClientReceiver();

    void receiver_data(std::vector<Coordinate>& coordenadas);
};

#endif  // CLIENT_RECEIVER_H
