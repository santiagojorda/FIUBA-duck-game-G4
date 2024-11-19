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
        // Inicia el bucle de eventos como: un usuario hace clic en un botón o cierra una ventana o se redibuja un widget
        // devuelve un código de estado cuando el bucle de eventos termina.
        int qt_status = a.exec();
        std::cout << qt_status << std::endl;
        if (qt_status == SUCCESS) {
            std::cout << "fue exitoso\n"; 
        }

        std::cout << "qt_status :" << qt_status << "\n";
        return SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "Ocurrió un problema: " << e.what() << '\n';
        return ERROR;
    } catch (...) {
        std::cerr << "Ocurrió un problema y una excepción desconocida fue capturada.\n";
        return ERROR;
    }
}
