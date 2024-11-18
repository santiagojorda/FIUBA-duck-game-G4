#include <exception>
#include <iostream>
#include <list>



#include "../common/coordinate.h"
#include "lobby/lobby.h"
#include "yamel/map_deserialize.h"

#define ERROR -1
#define SUCCESS 0
#define BAD_ARGUMENTS 1
#define ARGS_EXPECTED 2


int main() {

    try {
        std::cout << "Iniciando server" << std::endl;


        Lobby lobby;
        lobby.run();
        return SUCCESS;



        // if (argc == ARGS_EXPECTED) {
        // char* servname = argv[1];
        // Server server;
        // server.run();
        // return ...
        // } else {
        // std::cerr << "Bad call " << argv[0] << " <servname>" << std::endl;
        // return BAD_ARGUMENTS;
        // }

    } catch (const std::exception& error) {
        std::cerr << "Server error: " << error.what() << std::endl;
        return ERROR;
    } catch (...) {
        std::cerr << "Server error. There is not information." << std::endl;
        return ERROR;
    }
}