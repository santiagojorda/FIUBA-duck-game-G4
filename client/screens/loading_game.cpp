#include "loading_game.h"

#include "ui_loading_game.h"

LoadingGame::LoadingGame(int button_id,
                         QWidget* parent):
        QDialog(parent),
        ui(new Ui::LoadingGame),
        button_id(button_id)
        {
    ui->setupUi(this);

    if (button_id == 1) {
        ui->pushButton_2->setText("Start Game");
    } else if (button_id == 2) {
        ui->pushButton_2->hide();
        ui->labelReadyToStart->setText("Wait for the game to start");
    }
}

// Start Game
void LoadingGame::on_pushButton_2_clicked() { generate_conection(); }

void LoadingGame::generate_conection() {
    /*Socket skt(this->hostnameStr.c_str(), this->portStr.c_str());
    ClientProtocol protocol(skt);
    protocol.send_init(0xFF);
    */
}


LoadingGame::~LoadingGame() { delete ui; }
