#include "equippable.h"

#include "../player/player.h"

void Equippable::on_collision_with(Player& player, GameLogic& game_logic) {
    std::cout << "on collision equippable with player" << std::endl;
    player.on_collision_with(std::dynamic_pointer_cast<Equippable>(shared_from_this()), game_logic);    
};
void Equippable::on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic) {
    std::cout << "on collision equippable with projectile" << std::endl;
    projectile->on_collision_with(std::dynamic_pointer_cast<Equippable>(shared_from_this()), game_logic);    
};

void Equippable::handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) {
    std::cout << "handle_sollision equippable" << std::endl;
    other->on_collision_with(std::dynamic_pointer_cast<Equippable>(shared_from_this()), game_logic);    
};