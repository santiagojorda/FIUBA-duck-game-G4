#include "armor.h"

#include "../player/inventory.h"

Armor::Armor() : Equippable() {}

void Armor::equip(Inventory& inventory) { inventory.equip( std::shared_ptr<Armor>(this) ); };
