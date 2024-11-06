#ifndef EVENT_MOVE_RIGHT_H
#define EVENT_MOVE_RIGHT_H

#include "event_player.h"

class EventMoveRight: public EventPlayer {
private:
public:
    explicit EventMoveRight(uint8_t& _player_id);

    void execute(GameLogic& game_logic) override;

    ~EventMoveRight();
};


#endif  // EVENT_MOVE_RIGHT_H
