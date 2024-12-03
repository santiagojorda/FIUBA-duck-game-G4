#include "duck_state_slipping.h"

#include "../player.h"

#define SLIP_STEP 8
#define SLIP_TICKS_PER_FRAME 2

struct SlippingStateConfig {
    DuckStateType id = DuckStateType::SLIPPING;
    std::string name = "Sliping";
};
SlippingStateConfig slipping_config;

DuckStateSlipping::DuckStateSlipping(const uint8_t& _player_id):
        DuckState(slipping_config.id, slipping_config.name,
                  duck_state_frames[slipping_config.id].max_frames, _player_id) {}

void DuckStateSlipping::update_state(Player& player, GameLogic& game_logic) {
    tick++;
    if (tick % SLIP_TICKS_PER_FRAME == 0) {
        frame++;
    }
    int coef;
    if (player.get_direction() == Direction::LEFT) {
        coef = -1;
    } else {
        coef = 1;
    }

    if (has_reached_max_frames()) {
        player.idle();
    }
    game_logic.move(player, coef * SLIP_STEP, 0);


    // game_logic.move(player, 0, -JUMP_STEP);

    // if (has_reached_max_frames()) {
    //     player.fall(game_logic);
    //     return;
    // }
    // if (tick % JUMP_TICKS_PER_FRAME == 0) {
    //     increment_frame();
    // }
}

DuckStateSlipping::~DuckStateSlipping() {}
