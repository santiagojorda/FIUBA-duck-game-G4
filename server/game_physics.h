#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "../common/coordinate.h"

#include "positionable.h"

class GamePhysics {
private:
public:
    GamePhysics();

    /*
    // a esta tocando a target  (en la misma recta horizontal )
    */
    bool horizontal_touch(const Coordinate& a, const Coordinate& target);

    /*
    // a esta tocando a target  (en la misma recta vertical )
    */
    bool vertical_touch(const Coordinate& a, const Coordinate& target);


    /*
    // a esta tocando a target  (en la misma recta horizontal )
    */
    bool horizontal_touch(const Rectangle& a, const Rectangle& target);

    /*
    // a esta tocando a target  (en la misma recta vertical )
    */
    bool vertical_touch(const Rectangle& a, const Rectangle& target);

    /*
    // a esta dentro de b
    */
    bool inside(const Rectangle& a, const Rectangle& b);

    /*
    // a y b comparten espacio en algun punto
    */
    bool collision(const Rectangle& a, const Rectangle& b);


    void falling(Positionable& target, uint iter_frame);

    ~GamePhysics();
};

GamePhysics::GamePhysics() {}

GamePhysics::~GamePhysics() {}


#endif  // GAME_PHYSICS_H