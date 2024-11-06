#include "armor.h"

#include "../player/inventory.h"

Armor::Armor() {}

void Armor::equip(Inventory* inventory) {
    inventory->equip(this);
};