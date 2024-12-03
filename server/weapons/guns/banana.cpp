#include "banana.h"
#include "../../player/player.h"

gun_config banana_config = { WeaponTextureID::BANANA, 1, ShootingRecoil::NONE, ProjectileRange::MEDIUM, 1, 1};

Banana::Banana(const Coordinate& _coordinate):
        Gun(banana_config, _coordinate), is_ready_to_slide(false) {}

void Banana::trigger_out(ListProjectiles& projectiles, const uint8_t& player_id,bool& was_dropped) {
    Gun::trigger_out(projectiles, player_id, was_dropped);
    was_dropped = true;
}
// void Banana::on_collision_with(Collidable& other, GameLogic& game_logic) {
//         std::cout << "handle_collision banana" << std::endl;
//         other.on_collision_with(*this, game_logic);
// }
// void Banana::on_collision_with(Player& player, GameLogic& game_logic) {
//     std::cout << "Collision banana con player" << std::endl;
//     (void)game_logic;
//     if(is_ready_to_slide){
//         player.slip();
//         die();
//     }
// }

Banana::~Banana() {}
