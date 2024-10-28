#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "../common/coordinate.h"

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
    // a esta dentro de b
    */
    bool inside(const Coordinate& a, const Coordinate& b);

    /*
    // a y b comparten espacio en algun punto
    */
    bool collision(const Coordinate& a, const Coordinate& b);

    void faling(Coordinate& coordinate, uint iter_frame);

    ~GamePhysics();
};

GamePhysics::GamePhysics() {}

GamePhysics::~GamePhysics() {}


#endif  // GAME_PHYSICS_H