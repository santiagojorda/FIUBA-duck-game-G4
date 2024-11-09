#include <exception>
#include <iostream>

#include "menu/menu_principal.h"

#include "client.h"

#define ARGS_EXPECTED_CLIENT 3
#define SUCCESS 0
#define ERROR -1

int main(int argc, char* argv[]) {
    try {
        MenuPrincipal menu_principal;

        menu_principal.run(argc, argv);
        // QApplication app(argc, argv);
        // return app.exec();
        /*if (argc != ARGS_EXPECTED_CLIENT) {
            std::cerr << "Cantidad de argumentos inválido" << std::endl;
            return ERROR;
        }

        std::string hostname = argv[1];
        std::string servname = argv[2];

        Client client(hostname, servname);
        client.run();*/
        return SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "Ocurrió un problema: " << e.what() << '\n';
        return ERROR;
    } catch (...) {
        std::cerr << "Ocurrió un problema y una excepción desconocida fue capturada.\n";
        return ERROR;
    }
}
