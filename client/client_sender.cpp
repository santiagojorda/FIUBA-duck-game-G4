#include "client_sender.h"

ClientSender::ClientSender(ClientProtocol& protocol, Queue<uint8_t>& commands):
        protocol(protocol), commands(commands) {}


void ClientSender::run() {
    try {
        while (this->is_alive()) {
            // if (this->protocol.is_closed()) {}
            uint8_t message_to_send = this->commands.pop();
            int id = 0;
            this->protocol.send_action(id, message_to_send);
            message_to_send = id++;
        }
    } catch (const ClosedQueue& e) {
        this->_is_alive = false;
        std::cerr << "Queue was closed" << std::endl;
    } catch (const std::exception& e) {
        this->_is_alive = false;
    }
}

ClientSender::~ClientSender() {
    if (this->is_alive()) {
        this->join();
    }
}
