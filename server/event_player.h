#ifndef EVENT_PLAYER_H
#define EVENT_PLAYER_H

#include <cstdint>

#include "event.h"
#include "player.h"

class EventPlayer: public Event {
protected:
    uint8_t id_player;

public:
    EventPlayer();

    void set_id(const uint8_t& id_player);

    virtual void transform_player(Player& player) = 0;

    const uint8_t& get_id() const;  // Cambiado a get_id

    virtual ~EventPlayer();
};

#endif  // EVENT_PLAYER_H
