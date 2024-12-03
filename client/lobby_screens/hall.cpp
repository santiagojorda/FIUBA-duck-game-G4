#include "hall.h"

#include "ui_hall.h"

Hall::Hall(QWidget* parent): QWidget(parent), ui(new Ui::Hall) {
    ui->setupUi(this);
    if (this->type_screen == 1) {
        data_for_client();
    }
    /* else {
        data_for_host();
    }*/
}

void Hall::set_config_game(std::tuple<int, std::string, std::string, int> config) {
    this->type_screen = std::get<0>(config);
    this->hostname = std::get<1>(config);
    this->port = std::get<2>(config);
    this->cant_players = std::get<3>(config);
    // data_for_host();
}

void Hall::data_for_host() {
    // Socket skt(this->hostname.c_str(), this->port.c_str());
    // ClientProtocol protocol(skt);
    // ClientReceiverLobby receiver_lobby(protocol, this->game_data);
    // receiver_lobby.start();

    // esto no deberia estar aca
    // Client client(std::move(skt), this->cant_players);
    Client client(this->hostname, this->port);
    // this->client = client;
    client.run();
}

void Hall::data_for_client() {
    // Socket skt(this->hostname.c_str(), this->port.c_str());
    // ClientProtocol protocol(skt);
    // ClientReceiverLobby receiver_lobby(protocol, this->game_data);
    // receiver_lobby.run();

    // Client client(skt, this->cant_players);
    Client client(this->hostname, this->port, this->cant_players);
    // this->client = client;
    client.run();
    client.active_drawer();
    QApplication::quit();
}

void Hall::initialize_screen() {
    if (!is_initialized) {
        is_initialized = true;
        if (this->cant_players == 1) {
            ui->containerTwoPlayers->hide();
        } else {
            ui->containerOnlyOnePlayer->hide();
        }

        if (this->type_screen == 1) {
            ui->buttonStartGame->hide();
        } else {
            ui->labelWaiting->hide();
        }
    }
}

Hall::~Hall() { delete ui; }

void Hall::on_buttonStartGame_clicked() {
    // recibe canti de player y etc, config game
    // cuando recibo byte de start game, se lo paso al cliente
    Client client(this->hostname, this->port, this->cant_players);
    client.run();

    Socket skt_dumy(this->hostname.c_str(), this->port.c_str());
    ClientProtocol protocol(skt_dumy);
    protocol.send_init(0xFF);

    client.active_drawer();

    QApplication::quit();
}
