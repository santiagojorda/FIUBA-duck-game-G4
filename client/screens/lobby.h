#ifndef LOBBY_H
#define LOBBY_H

#include "lobby_form.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Lobby;
}
QT_END_NAMESPACE

class Lobby : public QMainWindow
{
    Q_OBJECT

public:
    Lobby(QWidget *parent = nullptr);
    ~Lobby();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Lobby *ui;
};
#endif // LOBBY_H
