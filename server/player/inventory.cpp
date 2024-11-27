#include "inventory.h"

#include "../equipment/armor.h"
#include "../equipment/helmet.h"
#include "../weapons/gun.h"

Inventory::Inventory(): gun(nullptr), armor(nullptr), helmet(nullptr) {}

void Inventory::equip(std::shared_ptr<Equippable> new_item) { new_item->equip(*this); }

void Inventory::equip(std::shared_ptr<Gun> new_gun) {
    if (!gun) {
        gun = std::move(new_gun);
    }
}

void Inventory::equip(std::shared_ptr<Armor> new_armor) {
    if (!armor) {
        armor = std::move(new_armor);
    }
}

void Inventory::equip(std::shared_ptr<Helmet> new_helmet) {
    if (!helmet) {
        helmet = std::move(new_helmet);
    }
}

// void Inventory::equip_item(std::shared_ptr<Equippable> new_item, std::shared_ptr<Equippable> current_item){
//     if (!current_item) {
//         helmet = std::move(new_helmet);
//     }
// }

std::shared_ptr<Gun> Inventory::get_gun() { return gun; }
std::shared_ptr<Armor> Inventory::get_armor() { return armor; }
std::shared_ptr<Helmet> Inventory::get_helmet() { return helmet; }


void Inventory::drop_gun(GamePhysics& physics){ 
    if(gun){
        physics.handle_drop(gun);
        gun.reset();
    }
    else{
        (void)physics;
    }    
}
void Inventory::drop_armor(GamePhysics& physics){ drop_item(armor, physics);}
void Inventory::drop_helmet(GamePhysics& physics){ drop_item(helmet, physics); }


// void Inventory::drop_item(std::shared_ptr<Positionable> item, GamePhysics physics){
//     if(item){
//         physics.handle_drop(item);
//         item.reset();
//     }
//     else{
//         (void)physics;
//     }
// }

Inventory::~Inventory() {
}