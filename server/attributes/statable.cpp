#include "statable.h"

Statable::Statable() {}
void Statable::set_state(uint8_t new_state) { state = new_state;};
void Statable::set_frame(uint8_t new_frame) { frame = new_frame;};
uint8_t Statable::get_state() { return state; };
uint8_t Statable::get_frame() { return frame; };
Statable::~Statable() {}