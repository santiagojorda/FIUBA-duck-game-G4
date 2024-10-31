#include "game_logic.h"

GameLogic::GameLogic(std::list<Player>& _players) : players(_players) {}

void GameLogic::get_player(Player& player, uint8_t player_id){
    for(Player& player_aux : players){
        if (player_aux.get_id() == player_id) {
            player = player_aux;
            return;
        }
    }
}

void GameLogic::move_left_player(uint8_t player_id){
    Player player;
    get_player(player, player_id);

    if (player.get_id() == player_id) {
        player.translate_x(-1);
    }
}

void GameLogic::move_right_player(uint8_t player_id){
    Player player;
    get_player(player, player_id);

    if (player.get_id() == player_id) {
        player.translate_x(1);
    }
}

GameLogic::~GameLogic() {}
