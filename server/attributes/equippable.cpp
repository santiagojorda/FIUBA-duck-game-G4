#include "equippable.h"

#include "../player/player.h"

void Equippable::on_collision_with(Player& player, GameLogic& game_logic) {
    std::cout << "on collision equippable with player" << std::endl;
    player.on_collision_with(shared_from_this(), game_logic);    
};