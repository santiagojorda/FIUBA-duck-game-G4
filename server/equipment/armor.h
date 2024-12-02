#ifndef ARMOR_H
#define ARMOR_H

#include "../attributes/equippable.h"
#include "../../common/equippament_id.h"

class Armor: public Equippable {
public:
    Armor(const Coordinate& _coordinate) : Equippable((uint8_t)EquippamentTextureID::ARMOR, _coordinate) {}

    void handle_equip(Inventory& inventory) override { inventory.equip(std::shared_ptr<Armor>(this)); }
    std::shared_ptr<Equippable> clone() const override {
            return std::make_shared<Armor>(*this); 
    }
};

#endif