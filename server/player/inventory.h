#ifndef INVENTORY
#define INVENTORY

#include "../attributes/equippable.h"

class Gun;
class Armor;
class Helmet;

class Inventory {
private:
    std::shared_ptr<Gun> gun;
    std::shared_ptr<Armor> armor;
    std::shared_ptr<Helmet> helmet;

public:
    Inventory();
    void equip(std::shared_ptr<Equippable> new_item);
    void equip(std::shared_ptr<Gun> new_gun);
    void equip(std::shared_ptr<Armor> new_armor);
    void equip(std::shared_ptr<Helmet> new_helmet);
    std::shared_ptr<Gun> get_gun();
    std::shared_ptr<Armor> get_armor();
    std::shared_ptr<Helmet> get_helmet();
    ~Inventory();
};

#endif
