#ifndef GUN
#define GUN  

#include "../attributes/positionable.h"
#include "../attributes/statable.h"
#include "../player/player.h"

class Gun : public Positionable, public Statable {
private:
    uint8_t ammo; 

public:
    explicit Gun(uint8_t _ammo);
    virtual void shoot(Player player) = 0;
};

#endif
