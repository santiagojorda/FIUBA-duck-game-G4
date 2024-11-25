#include "duck_state_falling.h"

#include "../../attributes/positionable.h"

#define FALLING_STEP 5

struct FallingStateConfig {
    DuckStateType id = DuckStateType::FALLING;
    std::string name = "Falling";
};
FallingStateConfig falling_config;

DuckStateFalling::DuckStateFalling(const uint8_t& _player_id):
        DuckState(falling_config.id, falling_config.name,
                  duck_state_frames[falling_config.id].max_frames, _player_id) {}

void DuckStateFalling::update_state(Positionable& positionable, GamePhysics& physics) {
    positionable.translate_y(FALLING_STEP);
    frame_handler.increment_frame();
    (void)physics;
}
DuckStateFalling::~DuckStateFalling() {}
