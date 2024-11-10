#ifndef LOBBY_FORM_H
#define LOBBY_FORM_H

#include <QMainWindow>

namespace Ui {
class lobby_form;
}

class lobby_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit lobby_form(QWidget *parent = nullptr);
    ~lobby_form();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::lobby_form *ui;
};

#endif // LOBBY_FORM_H
