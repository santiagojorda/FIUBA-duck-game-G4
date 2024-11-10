#include "statable.h"

Statable::Statable() {}
uint8_t Statable::get_state() { return state; };
uint8_t Statable::get_frame() { return iter_frame; };
Statable::~Statable() {}