
#ifndef EVENT_MOVE_LEFT_H
#define EVENT_MOVE_LEFT_H

#include "event_player.h"
#include "game_logic.h"

class EventMoveLeft: public EventPlayer {
private:
public:
    EventMoveLeft(uint8_t& _player_id);

    virtual void execute(GameLogic& _game_logic) override;

    ~EventMoveLeft();
};


#endif  // EVENT_MOVE_LEFT_H
