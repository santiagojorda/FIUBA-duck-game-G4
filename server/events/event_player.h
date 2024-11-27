#ifndef EVENT_PLAYER_H
#define EVENT_PLAYER_H

#include <cstdint>

#include "../../common/action_events.h"
#include "../game/game_logic.h"
#include "../player/player.h"

class EventPlayer {
protected:
    // cppcheck-suppress unusedStructMember
    uint8_t& player_id;
    ActionEvent action_event;

public:
    explicit EventPlayer(uint8_t& player_id, const ActionEvent& _action_event);

    virtual void start(GameLogic& game_logic);
    
    virtual void execute(Player& player, GameLogic& game_logic) = 0; 

    virtual ~EventPlayer();
};

#endif  // EVENT_PLAYER_H
