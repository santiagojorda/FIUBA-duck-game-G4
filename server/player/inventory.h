#ifndef INVENTORY
#define INVENTORY

#include "../attributes/equippable.h"

class Gun;
class Armor;
class Helmet;

class Inventory {
private:
    Gun* gun;
    Armor* armor;
    Helmet* helmet;

public:
    Inventory();
    void equip(Equippable* new_item);
    void equip(Gun* new_gun);
    void equip(Armor* new_armor);
    void equip(Helmet* new_helmet);
    Gun* get_gun();
    Armor* get_armor();
    Helmet* get_helmet();
    ~Inventory();
};

#endif
