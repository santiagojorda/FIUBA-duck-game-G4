#include "lobby.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int id = QFontDatabase::addApplicationFont(":/fonts/fuentes/pixel_digivolve/Pixel_Digivolve.otf");
    if (id == -1) {
        qDebug() << "Error al cargar la tipografía";
        return -1;
    }

    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);

    if (fontFamilies.isEmpty()) {
        qDebug() << "No se encontró ninguna familia para la tipografía";
        return -1;
    }

    QString fontFamily = fontFamilies.at(0);
    QFont customFont(fontFamily);
    customFont.setPointSize(16);
    QApplication::setFont(customFont);


    Lobby w;
    w.show();
    return a.exec();
}
