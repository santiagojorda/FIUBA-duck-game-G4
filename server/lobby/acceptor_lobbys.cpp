#include "acceptor_lobbys.h"




AcceptorLobbys::AcceptorLobbys(MonitorLobbys& _monitor, Queue<std::string>& _queue) : Thread(),  monitor(_monitor),  queue(_queue) {}

void AcceptorLobbys::run(){
    try
    {
        while (this->is_alive()) {
            std::cout << "ACCEPTOR LOBY WIAIT " << std::endl;

            std::string server_name  = this->queue.pop();
            std::cout << "tengo en el acperor el " << server_name << std::endl;
            monitor.add_item(server_name.c_str());
        }
    }
    catch(const std::exception& e)
    {
        this->stop();
        std::cerr << e.what() << " error acceptor lobby" << '\n';
    }
}


AcceptorLobbys::~AcceptorLobbys() { 
    Thread::~Thread();
}
