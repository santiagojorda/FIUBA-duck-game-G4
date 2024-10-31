#ifndef EVENT_H
#define EVENT_H

#include "game_logic.h"

class Event {
private:
public:
    Event() {}
    virtual void execute(GameLogic& _game_logic) = 0;
    virtual ~Event() {}
};

#endif  // EVENT_H
