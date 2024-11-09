#ifndef PROBANDO2_H
#define PROBANDO2_H

#include <QMainWindow>

namespace Ui {
class Probando2;
}

class Probando2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Probando2(QWidget *parent = nullptr);
    ~Probando2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Probando2 *ui;
};

#endif // PROBANDO2_H
