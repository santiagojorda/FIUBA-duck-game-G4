#include "helmet.h"

#include "../player/inventory.h"

Helmet::Helmet() : Equippable() {}

void Helmet::equip(Inventory& inventory) { inventory.equip(std::shared_ptr<Helmet>(this)); };