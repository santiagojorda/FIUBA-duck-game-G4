#include "client_sender.h"

ClientSender::ClientSender(ClientProtocol& protocol, Queue<std::vector<uint8_t>>& commands):
        protocol(protocol), commands(commands) {}


void ClientSender::run() {
    try {
        while (this->is_alive()) {
            // if (this->protocol.is_closed()) {}
            std::vector<uint8_t> message_to_send = this->commands.pop();
            // this->protocol.send_message(mensaje_enviar);
        }
    } catch (const ClosedQueue& e) {
        this->_is_alive = false;
        std::cerr << "Queue was closed" << std::endl;
    } catch (const std::exception& e) {
        this->_is_alive = false;
    }
}

ClientSender::~ClientSender() { this->join(); }
