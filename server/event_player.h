#ifndef EVENT_PLAYER_H
#define EVENT_PLAYER_H

#include <cstdint>

#include "event.h"
#include "player.h"
#include "game_logic.h"

class EventPlayer: public Event {
protected:
    uint8_t player_id;

public:
    EventPlayer();

    void set_id(const uint8_t& _player_id);

    // virtual void transform_player(Player& player) = 0;

    // const uint8_t& set_id() const;
    
    virtual ~EventPlayer();
};

#endif  // EVENT_PLAYER_H
