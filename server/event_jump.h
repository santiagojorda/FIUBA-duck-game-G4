#ifndef EVENT_JUMP_H
#define EVENT_JUMP_H

#include "event_player.h"
#include "game_logic.h"

class EventJump: public EventPlayer {
private:
public:
    explicit EventJump(uint8_t& _player_id);

    virtual void execute(GameLogic& _game_logic) override;

    ~EventJump();
};

#endif  // EVENT_MOVE_LEFT_H
