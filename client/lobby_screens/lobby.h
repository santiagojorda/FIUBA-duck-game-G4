#ifndef LOBBY_H
#define LOBBY_H

#include <QWidget>

#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Lobby;
}
QT_END_NAMESPACE

class Lobby: public QWidget {
    Q_OBJECT

public:
    Lobby(QWidget* parent = nullptr);
    ~Lobby();

private slots:
    void on_buttonExit_clicked();

    void on_buttonJoinGame_clicked();

    void on_buttonNewGame_clicked();

private:
    Ui::Lobby* ui;
    Form form;
};
#endif  // LOBBY_H
