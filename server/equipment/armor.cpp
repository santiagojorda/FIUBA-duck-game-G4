#include "armor.h"

#include "../player/inventory.h"

Armor::Armor() : Equippable() {}

void Armor::handle_equip(Inventory& inventory) { inventory.equip( std::shared_ptr<Armor>(this) ); };

std::shared_ptr<Equippable> Armor::clone() const {
        return std::make_shared<Armor>(*this); 
}