#ifndef EVENT_SHOOT_H
#define EVENT_SHOOT_H

#include "event_player.h"


class EventShoot : public EventPlayer {
private:
public:
    explicit EventShoot(uint8_t& _player_id);

    virtual void execute(GameLogic& _game_logic) override;

    ~EventShoot();
};







#endif // EVENT_SHOOT_H
