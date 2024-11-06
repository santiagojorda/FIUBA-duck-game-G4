#ifndef GUN
#define GUN  

#include "../attributes/positionable.h"
#include "../attributes/statable.h"
#include "../attributes/equippable.h"
#include "../player/player.h"

class Player;

class Gun : public Positionable, public Equippable {
private:
    uint8_t ammo; 

public:
    explicit Gun(uint8_t _ammo);
    virtual void shoot(Player player) = 0;
    void equip(Inventory* inventory) override;
};

#endif
