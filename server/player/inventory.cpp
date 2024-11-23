#include "inventory.h"

#include "../equipment/armor.h"
#include "../equipment/helmet.h"
#include "../weapons/gun.h"

Inventory::Inventory(): gun(nullptr), armor(nullptr), helmet(nullptr) {}

void Inventory::equip(Equippable* new_item) { new_item->equip(this); }

void Inventory::equip(Gun* new_gun) {
    if (!gun) {
        gun = new_gun;
    }
}

void Inventory::equip(Armor* new_armor) {
    if (!armor) {
        armor = new_armor;
    }
}

void Inventory::equip(Helmet* new_helmet) {
    if (!helmet) {
        helmet = new_helmet;
    }
}

Gun* Inventory::get_gun() { return gun; }
Armor* Inventory::get_armor() { return armor; }
Helmet* Inventory::get_helmet() { return helmet; }

Inventory::~Inventory() {
    delete gun;
    delete armor;
    delete helmet;
}