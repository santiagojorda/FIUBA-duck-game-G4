#include "lobby.h"

#include <QMessageBox>

#include "./ui_lobby.h"

Lobby::Lobby(QWidget* parent): QMainWindow(parent), ui(new Ui::Lobby) { ui->setupUi(this); }

Lobby::~Lobby() { delete ui; }

// Join Game
void Lobby::on_pushButton_2_clicked() {
    connect(ui->pushButton_2, &QPushButton::clicked, [this]() { openLobbyForm(2); });
}

// New Game
void Lobby::on_pushButton_clicked() {
    connect(ui->pushButton, &QPushButton::clicked, [this]() { openLobbyForm(1); });
}


void Lobby::on_pushButton_3_clicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        this->close();
    }
}

void Lobby::openLobbyForm(int button_id) {
    lobby_form lobbyForm(button_id, this);
    lobbyForm.exec();
}