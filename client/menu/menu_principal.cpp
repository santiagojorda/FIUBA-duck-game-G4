#include "menu_principal.h"
#include <iostream>
#include <QPushButton>

MenuPrincipal::MenuPrincipal() {}

void MenuPrincipal::run(int argc, char** argv) {
    QApplication app(argc, argv);
    

    Probando2 window;
    window.show();
    // ClientLobby w(q_cmds, q_responses, new_map_info);

    //QPushButton button("hello world");
    //button.show();
    int qt_status = app.exec();
    std::cout << qt_status << std::endl;
}
