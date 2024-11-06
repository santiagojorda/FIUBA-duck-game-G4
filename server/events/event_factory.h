#ifndef EVENT_FACTORY_h
#define EVENT_FACTORY_h

#include <cstdint>
#include <map>

#include "../../common/action_commands.h"

#include "event_player.h"

class EventFactory {
private:
    // cppcheck-suppress unusedStructMember
    std::map<uint8_t, EventPlayer*> map_event;

    // cppcheck-suppress unusedStructMember
    uint8_t& player_id;

public:
    explicit EventFactory(uint8_t& _player_id);
    explicit EventFactory(const EventFactory& _other);

    EventPlayer* get_event(uint8_t id_event);

    ~EventFactory();
};

#endif  // EVENT_FACTORY_h
