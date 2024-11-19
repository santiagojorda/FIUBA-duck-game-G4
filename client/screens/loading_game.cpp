#include "loading_game.h"

#include "ui_loading_game.h"

LoadingGame::LoadingGame(int button_id, std::string hostname, std::string servname, int cantPlayers,
                         Client& client, QWidget* parent):
        QDialog(parent),
        ui(new Ui::LoadingGame),
        button_id(button_id),
        hostname(hostname),
        servname(servname),
        cantPlayers(cantPlayers),
        client(client) {
    ui->setupUi(this);

    if (button_id == 1) {
        ui->pushButton_2->setText("Start Game");
    } else if (button_id == 2) {
        this->client.active_drawer();
        ui->pushButton_2->hide();
        ui->labelReadyToStart->setText("Wait for the game to start");
    }

    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoadingGame::generate_connection);
}

// Start Game
void LoadingGame::on_pushButton_2_clicked() {
    // generate_conection();
}

void LoadingGame::generate_connection() {
    Socket skt(this->hostname.c_str(), this->servname.c_str());
    ClientProtocol protocol(skt);
    protocol.send_init(0xFF);
    this->client.active_drawer();
}


LoadingGame::~LoadingGame() { delete ui; }
