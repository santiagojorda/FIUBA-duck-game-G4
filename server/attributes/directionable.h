#ifndef  DIRECTIONABLE_H
#define DIRECTIONABLE_H

#include "../../common/direction.h"


class Directionable{
private:
    Direction direction;

public:
    Directionable(const Direction& _diretion);

    virtual Direction get_direction() const;

    virtual Direction set_direction(const Direction& diretion);

    virtual int  get_direction_int();

    ~Directionable();
};

Directionable::Directionable(const Direction& _diretion) : direction(_diretion)  {}

virtual Directionable::Direction get_direction() const { return this->direction; }

virtual Directionable::Direction set_direction(const Direction& new_diretion){
    this->direction = new_diretion;
}

virtual int  Directionable::get_direction_int() {
    return (this->direction == Direction::RIGHT) ? 1 : -1;
}

Directionable::~Directionable() {}














#endif // DIRECTIONABLE_H
