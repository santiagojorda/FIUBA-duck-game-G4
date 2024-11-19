#ifndef LOADING_GAME_H
#define LOADING_GAME_H

#include <QWidget>

#include "../../common/socket.h"
#include "../client.h"
#include "../protocol/protocol_client.h"

namespace Ui {
class LoadingGame;
}

class LoadingGame: public QWidget {
    Q_OBJECT

public:
    explicit LoadingGame(int button_id, std::string& hostnameStr, std::string& portStr,
                         QWidget* parent = nullptr);
    ~LoadingGame();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::LoadingGame* ui;
    int button_id;
    std::string& hostnameStr;
    std::string& portStr;

    void generate_conection();
};

#endif  // LOADING_GAME_H
