#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "../../common/coordinate.h"
#include "../attributes/positionable.h"

class GamePhysics {
private:
public:
    GamePhysics();

    /*
    // a esta tocando a target  (en la misma recta horizontal )
    */
    // bool horizontal_touch(const Coordinate& a, const Coordinate& b);

    // /*
    // // a esta tocando a b  (en la misma recta vertical )
    // */
    // bool vertical_touch(const Coordinate& a, const Coordinate& b);


    // /*
    // // a esta tocando a b  (en la misma recta horizontal )
    // */
    // bool horizontal_touch(const Rectangle& a, const Rectangle& b);

    // /*
    // // a esta tocando a b  (en la misma recta vertical )
    // */
    // bool vertical_touch(const Rectangle& a, const Rectangle& b);

    // /*
    // // a esta dentro de b
    // */
    // bool inside(const Rectangle& a, const Rectangle& b);


    // bool touch(const Rectangle& a, const Rectangle& b);
    
    /*
    // a y b comparten espacio en algun punto
    */
    bool collision(const Rectangle& a, const Rectangle& b);

    void falling(Positionable& target, uint iter_frame);

    ~GamePhysics();
};


#endif  // GAME_PHYSICS_H