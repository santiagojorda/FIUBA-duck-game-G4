#ifndef EVENT_FACTORY_h
#define EVENT_FACTORY_h


#include <cstdint>
#include <map>

#include "../common/action_commands.h"

#include "event.h"

class EventFactory {
private:
    std::map<uint8_t, EventPalyer*> map_event;

public:
    EventFactory();

    Event* get_event(uint8_t id_event, uint8_t id_player);


    ~EventFactory();
};

#endif  // EVENT_FACTORY_h
