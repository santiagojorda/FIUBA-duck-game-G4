#include "statable.h"

Statable::Statable(const uint8_t& _initial_state): state(_initial_state) {}

void Statable::set_state(const uint8_t& new_state) {
    if (state != new_state) {
        state = new_state;
        tick = 0;
        frame = 0;
    }
};

uint8_t Statable::get_state() { return state; };
uint8_t Statable::get_frame() { return frame; };
uint8_t Statable::get_tick() { return tick; };

void Statable::reset() {
    frame = 0;
    tick = 0;
}
Statable::~Statable() {}