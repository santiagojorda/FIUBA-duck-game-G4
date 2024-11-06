#ifndef EVENT_CROUCH_H
#define EVENT_CROUCH_H

#include "event_player.h"

class EventCrouch: public EventPlayer {
private:
public:
    explicit EventCrouch(uint8_t& _player_id);

    virtual void execute(GameLogic& _game_logic) override;

    ~EventCrouch();
};

#endif  // EVENT_MOVE_LEFT_H
