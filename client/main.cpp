#include <exception>
#include <iostream>
#include <QApplication>
#include <QFontDatabase>
#include "lobby_screens/lobby.h"
#include "client_host.h"

#define ARGS_EXPECTED_CLIENT 3
#define SUCCESS 0
#define ERROR -1

std::string menu_terminal(ClientProtocol& protocol, bool& host) {
    std::string command;
    std::cout << "[1] Host" << std::endl;
    std::cout << "[2] Join" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> command;
    uint8_t byte_commad;
    switch (command[0]) {
        case '1':
            std::cout << "Creating a game on: ";
            protocol.send_init(0); // indicar host o join
            std::cin >> command;
            protocol.send_server_name(command); // le manda el puerto
            host = true;
            break;
        case '2':
            std::cout << "Joining a game on: " << std::endl;
            byte_commad = 1;
            protocol.send_init(byte_commad); // indicar host o join
            protocol.recv_init(byte_commad); // cantidad de partidas abiertas
            for (size_t i = 0; i < (size_t)byte_commad; i++) {
                std::cout << "[" << i << "] Join ?" << std::endl;
            }
            std::cin >> command;
            break;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
    }

    return command; // Return the user's input
}

int main(int argc, char* argv[]) {
    try {
        if (argc != ARGS_EXPECTED_CLIENT) {
            std::cerr << "Cantidad de argumentos inválido" << std::endl;
            return ERROR;
        }
        
        std::string hostname = argv[1];
        std::string servname = argv[2];
        std::cout << "Conection wiht server: " ;
        //Socket skt(hostname.c_str(), servname.c_str());
        // ClientProtocol protocol(skt);

        QApplication a(argc, argv);

        int id = QFontDatabase::addApplicationFont(
                ":/fonts/fuentes/pixel_digivolve/Pixel_Digivolve.otf");
        std::cout << "id: " << id << "\n";

        if (id == -1) {
            std::cerr << "Error al cargar la tipografía" << std::endl;
            return -1;
        }

        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);

        if (fontFamilies.isEmpty()) {
            std::cerr << "No se encontró ninguna familia para la tipografía" << std::endl;
            return -1;
        }

        QString fontFamily = fontFamilies.at(0);
        QFont customFont(fontFamily);
        customFont.setPointSize(16);
        QApplication::setFont(customFont);


        Lobby w(hostname, servname);
        w.show();
        return a.exec();

        /*bool hosts = false;
        std::string new_server = menu_terminal(protocol, hosts);
        if(hosts){
            std::string dumy;
            std::cout << "crete game..: ";
            std::cin >> dumy;
            ClientHost host(hostname, new_server);
            std::cout << "star party: ";
            std::cin >> dumy;
            host.init_game();
            host.join();
            std::cout << "iniciar juego" << std::endl;
        } else {
            Client client(hostname, new_server);
            client.run();
        }
        return SUCCESS;*/
    } catch (const std::exception& e) {
        std::cerr << "Ocurrió un problema: " << e.what() << '\n';
        return ERROR;
    } catch (...) {
        std::cerr << "Ocurrió un problema y una excepción desconocida fue capturada.\n";
        return ERROR;
    }
}
