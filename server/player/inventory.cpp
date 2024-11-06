#include "inventory.h"

#include "../guns/gun.h"
#include "../equipment/armor.h"
#include "../equipment/helmet.h"

Inventory::Inventory() :
    gun(nullptr),
    armor(nullptr),
    helmet(nullptr)
    {}

void Inventory::equip(Equippable* new_item){
    new_item->equip(this);
}

void Inventory::equip(Gun* new_gun){
    if(!gun){
        gun = new_gun;
    }
}

void Inventory::equip(Armor* new_armor){
    if(!armor){
        armor = new_armor;
    }
}

void Inventory::equip(Helmet* new_helmet){
    if(!helmet){
        helmet = new_helmet;
    }
}


Inventory::~Inventory() {
    delete gun;
    delete armor;
    delete helmet;
}