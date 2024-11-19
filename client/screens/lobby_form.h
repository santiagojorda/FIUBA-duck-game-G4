#ifndef LOBBY_FORM_H
#define LOBBY_FORM_H

#include <QDialog>

#include "../client.h"

#include "loading_game.h"

namespace Ui {
class lobby_form;
}

class lobby_form: public QDialog {
    Q_OBJECT

public:
    lobby_form(int button_id, QWidget* parent = nullptr);
    ~lobby_form();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::lobby_form* ui;
    int button_id;

    void open_loading_window(int _button_id, std::string hostnameStr, std::string portStr,
                             int cantPlayers, Client& client);
};

#endif  // LOBBY_FORM_H
