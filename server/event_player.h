#ifndef EVENT_PLAYER_H
#define EVENT_PLAYER_H

#include <cstdint>

#include "event.h"
#include "player.h"

class EventPalyer: public Event {
protected:
    uint8_t id_player;

public:
    EventPalyer();

    void set_id(const uint8_t& id_player);

    virtual void transform_player(Player& player) = 0;

    const uint8_t& set_id() const;

    virtual ~EventPalyer();
};

EventPalyer::EventPalyer() {}

EventPalyer::~EventPalyer() {}

#endif  // EVENT_PLAYER_H
