#include <exception>
#include <iostream>

#include "client.h"

#define ERROR -1
#define SUCCESS 0


int main() {
    try {
        /*if (argc != ARGS_EXPECTED_CLIENT) {
            std::cerr << "Cantidad de argumentos inválido" << std::endl;
            return ERROR;
        }

        std::string hostname = argv[1];
        std::string servname = argv[2];*/

        Client client;
        client.run();
        return SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "Ocurrió un problema: " << e.what() << '\n';
        return ERROR;
    } catch (...) {
        std::cerr << "Ocurrió un problema y una excepción desconocida fue capturada.\n";
        return ERROR;
    }
}
