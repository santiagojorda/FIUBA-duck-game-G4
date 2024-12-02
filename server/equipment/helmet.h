#ifndef HELMET_H
#define HELMET_H

#include "../attributes/equippable.h"
#include "../../common/equippament_id.h"

class Helmet: public Equippable {
public:
    Helmet(const Coordinate& _coordinate) : Equippable((uint8_t)EquippamentTextureID::HELMET, _coordinate) {}

    void handle_equip(Inventory& inventory) override { inventory.equip(std::shared_ptr<Helmet>(this)); }
    std::shared_ptr<Equippable> clone() const override {
            return std::make_shared<Helmet>(*this); 
    }

    
};

#endif
