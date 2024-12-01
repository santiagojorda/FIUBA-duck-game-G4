#include "hall.h"

#include "ui_hall.h"

Hall::Hall(QWidget* parent): QWidget(parent), ui(new Ui::Hall) { ui->setupUi(this); }

void Hall::set_config_game(std::tuple<int, std::string, std::string, int> config) {
    this->type_screen = std::get<0>(config);
    this->hostname = std::get<1>(config);
    this->port = std::get<2>(config);
    this->cant_players = std::get<3>(config);
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

void Hall::on_buttonStartGame_clicked() { QApplication::quit(); }
