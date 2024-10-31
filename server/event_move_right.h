#ifndef EVENT_MOVE_RIGHT_H
#define EVENT_MOVE_RIGHT_H

#include "event_player.h"


class EventMoveRight: public EventPlayer {
private:
public:
    EventMoveRight();

    virtual void transform_player(Player& player) override;

    ~EventMoveRight();
};


#endif  // EVENT_MOVE_RIGHT_H
