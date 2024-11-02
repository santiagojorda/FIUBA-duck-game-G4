#ifndef EVENT_PLAYER_H
#define EVENT_PLAYER_H

#include <cstdint>

#include "player.h"
#include "game_logic.h"

class EventPlayer {
protected:
    // cppcheck-suppress unusedStructMember
    uint8_t& player_id;

public:
    explicit EventPlayer(uint8_t& player_id);

    virtual void execute(GameLogic& game_logic) = 0;
    
    virtual ~EventPlayer();
};

#endif  // EVENT_PLAYER_H