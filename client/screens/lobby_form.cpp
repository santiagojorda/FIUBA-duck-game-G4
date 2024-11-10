#include "lobby_form.h"
#include "ui_lobby_form.h"

lobby_form::lobby_form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lobby_form)
{
    ui->setupUi(this);
}

lobby_form::~lobby_form()
{
    delete ui;
}

void lobby_form::on_pushButton_2_clicked()
{

}


void lobby_form::on_pushButton_clicked()
{

}

