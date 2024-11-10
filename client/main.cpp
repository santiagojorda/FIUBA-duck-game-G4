#include <exception>
#include <iostream>
#include <QApplication>
#include "lobby/principal_screen.h"

#include "client.h"

#define ARGS_EXPECTED_CLIENT 3
#define SUCCESS 0
#define ERROR -1

int main(int argc, char* argv[]) {
    try {
        QApplication a(argc, argv);
        PrincipalScreen principal_screen;
        principal_screen.show_screen();
        int qt_status = a.exec();
        std::cout << qt_status << std::endl;

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
