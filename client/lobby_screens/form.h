#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPainter>
#include "hall.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void set_type_screen(int type_screen);
    void initialize_screen();

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        QPixmap background(":/images/DuckSelection.png");
        painter.setOpacity(0.5);
        painter.drawPixmap(0, 0, width(), height(), background);
    }

private slots:
    void on_buttonContinue_clicked();

    void on_inputHostname_textChanged(const QString &arg1);

    void on_inputPort_textChanged(const QString &arg1);

    void on_spinNumberPlayers_valueChanged(int arg1);

private:
    Ui::Form *ui;
    Hall hall;
    std::string hostname;
    std::string port;
    int cant_players;
    int type_screen;
    bool is_initialized = false;
    bool validate_form();
};

#endif // FORM_H
