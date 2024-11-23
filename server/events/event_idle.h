#ifndef EVENT_IDLE_H
#define EVENT_IDLE_H

#include "event_player.h"

class EventIdle: public EventPlayer {
private:
public:
    explicit EventIdle(uint8_t& _player_id);

    virtual void execute(GameLogic& _game_logic) override;

    ~EventIdle();
};

#endif  // EVENT_IDLE_H