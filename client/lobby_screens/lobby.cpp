#include "lobby.h"

#include "./ui_lobby.h"

Lobby::Lobby(QWidget* parent): QWidget(parent), ui(new Ui::Lobby) {
    ui->setupUi(this);                          // el actual es index 0
    ui->stackedWidget->insertWidget(1, &form);  // insertamos en index 1
}

Lobby::~Lobby() { delete ui; }

void Lobby::on_buttonExit_clicked() { this->close(); }


void Lobby::on_buttonJoinGame_clicked() {
    form.set_type_screen(1);
    form.initialize_screen();
    ui->stackedWidget->setCurrentIndex(1);
}


void Lobby::on_buttonNewGame_clicked() {
    form.set_type_screen(2);
    form.initialize_screen();
    ui->stackedWidget->setCurrentIndex(1);
}
