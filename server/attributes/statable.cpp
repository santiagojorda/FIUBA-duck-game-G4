#include "statable.h"

Statable::Statable(DuckState initial_state) : state(initial_state){}

void Statable::set_state(DuckState new_state) {
    if(state != new_state){
        state = new_state;
        frame = 0;    
    }
};

DuckState Statable::get_state() { return state; };
void Statable::reset() { frame = 0; }
uint8_t Statable::get_frame() { return frame; };

Statable::~Statable() {}