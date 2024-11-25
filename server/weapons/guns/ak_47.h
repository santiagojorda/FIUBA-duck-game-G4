#ifndef AK_47_H
#define AK_47_H

#include "../gun.h"

class AK47: public Gun {
private:
public:
    explicit AK47(const Coordinate& _coordinate);

    // Dispara aumentado dispersion
    virtual void trigger(ListProjectiles& projectiles) override;

    // reinicia dispersion
    virtual void trigger_out(ListProjectiles& projectiles) override;

    ~AK47();
};

#endif
