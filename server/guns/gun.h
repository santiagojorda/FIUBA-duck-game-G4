#ifndef GUN
#define GUN  

#include "../positionable.h"

class Gun : public Positionable {
private:

    uint16_t ammo; 

public:
    virtual void shoot() = 0;
};

#endif
