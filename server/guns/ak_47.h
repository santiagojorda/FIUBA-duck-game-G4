#ifndef AK_47_H
#define AK_47_H

#include "../../common/weapons_id.h"

#include "gun.h"

class AK47: public Gun {
private:
    // ListProjectiles generate_list_projectiles(Coordinate& shooter_position) override;
public:
    explicit AK47(const Coordinate& _coordinate);
    
    ListProjectiles shoot(Coordinate& shooter_position) override;

    void shoot(ListProjectiles& projectiles, Direction direction) override;

    ~AK47();
};

#endif
