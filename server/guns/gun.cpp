#include "gun.h"

Gun::Gun(uint8_t _ammo) : ammo(_ammo) {}

void Gun::equip(Inventory* inventory) {
    inventory->equip(this);
};

