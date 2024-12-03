#ifndef CLIENT_HOST_H
#define CLIENT_HOST_H


#include "client.h"

class ClientHost : public Thread {
private:
    Client host;
    const std::string& hostname;
    const std::string& servname;

public:
    ClientHost(const std::string& hostname, const std::string& servname);

    void run() override;

    void init_game();

    ~ClientHost();
};

ClientHost::ClientHost(const std::string& hostname, const std::string& servname) : Thread(), host(hostname, servname) , hostname(hostname), servname(servname){
    this->start();
}


void ClientHost::init_game(){

    try
    {
        Socket skt_dumy(hostname.c_str(), servname.c_str());
        ClientProtocol protocol(skt_dumy);
        protocol.send_init(0xFF);
    }
    catch(const std::exception& e)
    {
        std::cerr  <<"no init gamer" << e.what()  << '\n';
    } catch (...) {
        std::cerr  <<"Unkow init gamer"  << '\n';

    }
    

}


void ClientHost::run(){
    try
    {
        this->host.run();
    } catch (const std::exception& e) {
        std::cerr << "in host error" << e.what() << '\n';
    }
}

ClientHost::~ClientHost() {
    Thread::~Thread();
}


#endif // CLIENT_HOST_H