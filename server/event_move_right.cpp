#include "event_move_right.h"

EventMoveRight::EventMoveRight() : EventPlayer() {}

// void EventMoveRight::transform_player(Player& player) {
//     if (player.get_id() == this->player_id) {
//         player.translate_x(1);
//     }
// }

void EventMoveRight::execute(GameLogic& game_logic) {
    game_logic.move_right_player(player_id);
}


EventMoveRight::~EventMoveRight() { EventPlayer::~EventPlayer();}
