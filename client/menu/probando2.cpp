#include "probando2.h"
#include "ui_probando2.h"

Probando2::Probando2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Probando2)
{
    ui->setupUi(this);
}

Probando2::~Probando2()
{
    delete ui;
}

void Probando2::on_pushButton_clicked()
{
    ui->labelSecond->setText("hola");
}
