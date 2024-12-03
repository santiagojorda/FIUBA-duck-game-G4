#ifndef HALL_H
#define HALL_H

#include <QWidget>

#include "../../common/socket.h"
#include "../protocol/protocol_client.h"

namespace Ui {
class Hall;
}

class Hall: public QWidget {
    Q_OBJECT

public:
    explicit Hall(QWidget* parent = nullptr);
    ~Hall();
    void set_config_game(std::tuple<int, std::string, std::string, int> config);
    void initialize_screen();
    void set_client_host();
    void set_client();

private slots:
    void on_buttonStartGame_clicked();

private:
    Ui::Hall* ui;
    int type_screen;
    std::string hostname;
    std::string port;
    int cant_players;
    bool is_initialized = false;
};

#endif  // HALL_H
