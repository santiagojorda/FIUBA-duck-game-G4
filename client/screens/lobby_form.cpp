#include "lobby_form.h"

#include <iostream>

#include "ui_lobby_form.h"

lobby_form::lobby_form(int button_id, QWidget* parent):
        QDialog(parent), ui(new Ui::lobby_form), button_id(button_id) {
    ui->setupUi(this);

    if (button_id == 1) {
        ui->pushButton_2->setText("Create Game");
    } else if (button_id == 2) {
        ui->pushButton_2->setText("Connect");
    }

    connect(ui->pushButton_2, &QPushButton::clicked, this, &lobby_form::on_pushButton_2_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &lobby_form::on_pushButton_clicked);
}

lobby_form::~lobby_form() { delete ui; }

void lobby_form::on_pushButton_2_clicked() {
    QString hostname = ui->inputHostname->text();
    QString port = ui->inputPort->text();
    int cantPlayers = ui->spinBox->value();

    std::string hostnameStr = hostname.toStdString();
    std::string portStr = port.toStdString();
    Client client(hostnameStr, portStr, cantPlayers);
    client.run();
    open_loading_window(button_id, hostnameStr, portStr, cantPlayers, client);
}

void lobby_form::on_pushButton_clicked() { this->close(); }

void lobby_form::open_loading_window(int _button_id, std::string hostnameStr, std::string portStr,
                                     int cantPlayers, Client& client) {
    LoadingGame loading_game(_button_id, hostnameStr, portStr, cantPlayers, client, this);
    loading_game.exec();
}
