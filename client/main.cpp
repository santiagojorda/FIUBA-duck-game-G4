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
        if (qt_status != SUCCESS) {
            std::cerr << "Hubo un error al cargar la partida.\n"; 
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
