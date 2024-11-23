#ifndef AK_47_H
#define AK_47_H

#include "../gun.h"

class AK47: public Gun {
private:
    int dispersion;

public:
    explicit AK47(const Coordinate& _coordinate);

    //Dispara aumentado dispersion 
    virtual void trigger(ListProjectiles& projectiles, Direction direction) override; 

    //reinicia dispersion 
    virtual void trigger_out(ListProjectiles& projectiles, Direction direction) override;

    ~AK47();
};

#endif
