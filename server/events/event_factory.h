// #ifndef EVENT_FACTORY_h
// #define EVENT_FACTORY_h

// #include <cstdint>
// #include <map>

// #include "../../common/action_events.h"

// #include "event_player.h"

// class EventFactory {
// private:
//     // cppcheck-suppress unusedStructMember
//     std::map<ActionEvent, EventPlayer*> map_event;

//     // cppcheck-suppress unusedStructMember
//     uint8_t& player_id;

// public:
//     explicit EventFactory(uint8_t& _player_id);
//     explicit EventFactory(const EventFactory& _other);

//     EventPlayer* get(ActionEvent id_event);

//     ~EventFactory();
// };

// #endif  // EVENT_FACTORY_h


#ifndef EVENT_FACTORY_h
#define EVENT_FACTORY_h

#include <cstdint>
#include <map>

#include "../../common/action_events.h"
#include "../utils/factory.h"

#include "event_player.h"
#include "event_move_left.h"
#include "event_move_right.h"
#include "event_jump.h"
#include "event_crouch.h"
#include "event_shoot.h"
#include "event_idle.h"

class EventFactory{
private:

    // cppcheck-suppress unusedStructMember
    std::map<ActionEvent, EventPlayer*> events;

    // cppcheck-suppress unusedStructMember
    uint8_t player_id;

public:
    explicit EventFactory(const uint8_t& _player_id) : player_id(_player_id) {
        add(ActionEvent::MOVE_LEFT, new EventMoveLeft(player_id));
        add(ActionEvent::MOVE_RIGHT, new EventMoveRight(player_id));
        add(ActionEvent::JUMP, new EventJump(player_id));
        add(ActionEvent::CROUCH, new EventCrouch(player_id));
        add(ActionEvent::SHOOT, new EventShoot(player_id));
        add(ActionEvent::IDLE, new EventIdle(player_id));
    }
    
    // hay que hacer por movimiento
    EventFactory(const EventFactory& _other): EventFactory(_other.player_id) {}

    void add(const ActionEvent& event_id, EventPlayer* event){
        events[event_id] = event;
    }

    EventPlayer* get(const ActionEvent& event_id) {
        return events[event_id];
    }

    ~EventFactory(){
        for (auto& event: events) {
            delete event.second;
        }
        events.clear();
    };
};

#endif  // EVENT_FACTORY_h
