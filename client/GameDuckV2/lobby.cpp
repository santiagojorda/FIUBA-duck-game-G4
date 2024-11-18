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

}


void Lobby::on_pushButton_clicked()
{

}


void Lobby::on_pushButton_3_clicked()
{

}

