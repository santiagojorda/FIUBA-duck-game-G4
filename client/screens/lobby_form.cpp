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
}

lobby_form::~lobby_form() { delete ui; }

void lobby_form::on_pushButton_2_clicked() {
    /*
    Queda así hasta resolver las múltiples partidas.
    */
    QString hostname = ui->inputHostname->text();
    QString port = ui->inputPort->text();
    int cantPlayers = ui->spinBox->value();

    std::string hostnameStr = hostname.toStdString();
    std::string portStr = port.toStdString();
    Client client(hostnameStr, portStr, cantPlayers);
    client.run();

    connect(ui->pushButton_2, &QPushButton::clicked, [this]() {
        open_loading_window(button_id);
    });
}

void lobby_form::on_pushButton_clicked() { this->close(); }

void lobby_form::open_loading_window(int _button_id) {
    LoadingGame loading_game(_button_id, this);
    loading_game.exec();
}
