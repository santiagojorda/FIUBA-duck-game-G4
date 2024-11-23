#ifndef ACTION_COMMANDS_H
#define ACTION_COMMANDS_H

enum HeaderProtocol {
    HEADER_CLIENT = 0xA,
    HEADER_SERVER = 0xB,
};

enum ActionCommand {
    MOVE_LEFT,        // Moverse a la izquierda
    MOVE_RIGHT,       // Moverse a la derecha
    JUMP,             // Salta / aletear
    GRAB_OR_RELEASE,  // Tomar / soltar un arma/casco/armadura
    SHOOT,            // Disparar
    AIM_UP,           // Apuntar hacia arriba
    CROUCH,           // Tirarse al piso
    IDLE              // nada
};

#endif  // ACTION_COMMANDS_H
