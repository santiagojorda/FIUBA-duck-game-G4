#ifndef GUN_FACTORY_H
#define GUN_FACTORY_H


#include "gun.h"

class GunFactory{
private:

public:
    GunFactory();

    Gun* create_gun(const int& id_weapon, const Coordinate& _coordinate);

    ~GunFactory();
};





#endif // GUN_FACTORY_H
