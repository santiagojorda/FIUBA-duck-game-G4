#ifndef LOADING_GAME_H
#define LOADING_GAME_H

#include <QDialog>

#include "../../common/socket.h"
#include "../client.h"
#include "../protocol/protocol_client.h"

namespace Ui {
class LoadingGame;
}

class LoadingGame: public QDialog {
    Q_OBJECT

public:
    LoadingGame(int button_id, std::string hostname, QWidget* parent = nullptr);
    ~LoadingGame();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::LoadingGame* ui;
    int button_id;
    std::string hostname;

    void generate_conection();
};

#endif  // LOADING_GAME_H
