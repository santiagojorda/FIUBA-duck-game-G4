#ifndef  DIRECTIONABLE_H
#define DIRECTIONABLE_H

#include "../../common/direction.h"


class Directionable{
protected:
    Direction direction;

public:
    Directionable(const Direction& _diretion);

    virtual Direction get_direction() const;

    virtual void set_direction(const Direction& diretion);

    virtual int  get_direction_int();

    virtual ~Directionable();
};

#endif // DIRECTIONABLE_H
