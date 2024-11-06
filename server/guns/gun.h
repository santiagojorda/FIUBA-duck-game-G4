#ifndef GUN
#define GUN  

#include "../position/positionable.h"

class Gun : public Positionable {
private:

    uint16_t ammo; 

public:
    virtual void shoot() = 0;
};

#endif
