#include "event_move_left.h"

EventMoveLeft::EventMoveLeft() : EventPlayer() {}

// void EventMoveLeft::transform_player(Player& player) {
//     if (player.get_id() == this->player_id) {
//         player.translate_x(-1);
//     }
// }

void EventMoveLeft::execute(GameLogic& game_logic) {
    game_logic.move_left_player(player_id);
}


EventMoveLeft::~EventMoveLeft() {EventPlayer::~EventPlayer();}
