#include <exception>
#include <iostream>
#include <QApplication>
#include "lobby/principal_screen.h"
#include "client.h"
#include "config/game_config.h"
/*
int main(int argc, char *argv[]) {
    try {
        if (argc != ARGS_EXPECTED_CLIENT) {
            std::cerr << "Cantidad de argumentos inválido" << std::endl;
            return ERROR;
        }

        std::string hostname = argv[1];
        std::string servname = argv[2];

        Client client(hostname, servname);
        client.run();
        return SUCCESS;

        QApplication a(argc, argv);
        PrincipalScreen principal_screen;
        principal_screen.show_screen();
        int qt_status = a.exec();
        if (qt_status != SUCCESS) {
            std::cerr << "Ocurrió un problema al cargar la partida.\n"; 
            return ERROR;
        }
      
        return SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "Ocurrió un problema: " << e.what() << '\n';
        return ERROR;
    } catch (...) {
        std::cerr << "Ocurrió un problema y una excepción desconocida fue capturada.\n";
        return ERROR;
    }
}
*/