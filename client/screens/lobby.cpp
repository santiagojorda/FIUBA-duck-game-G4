#include "lobby.h"
#include "./ui_lobby.h"

Lobby::Lobby(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lobby)
{
    ui->setupUi(this);
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::on_pushButton_2_clicked()
{
    // Crear una nueva instancia de LobbyForm
    LobbyForm *lobbyForm = new LobbyForm(this);

    // Mostrar la nueva interfaz
    lobbyForm->show();
}


void Lobby::on_pushButton_clicked()
{

}


void Lobby::on_pushButton_3_clicked()
{

}

