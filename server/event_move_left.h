
#ifndef EVENT_MOVE_LEFT_H
#define EVENT_MOVE_LEFT_H

#include "event_player.h"
#include "game_logic.h"

class EventMoveLeft: public EventPlayer {
private:
public:
    EventMoveLeft();

    // virtual void transform_player(Player& player) override;
    virtual void execute(GameLogic& _game_logic) override;

    ~EventMoveLeft();
};


#endif  // EVENT_MOVE_LEFT_H
