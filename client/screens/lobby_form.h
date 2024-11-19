#ifndef LOBBY_FORM_H
#define LOBBY_FORM_H

#include <QDialog>
#include <QMainWindow>
#include "loading_game.h"

#include "../client.h"

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
    std::string hostname;

    void open_loading_window(int _button_id);
};

#endif  // LOBBY_FORM_H
