#include "projectile.h"
// #include "../game/game_physics.h"
#include "../game/game_logic.h"
#include "../player/player.h"

Projectile::Projectile(const uint8_t& texture_id, ProjectileRange _range_tiles,
                       Coordinate _coordinate, const Direction& _direction, const uint8_t& _shooter_id):
        Positionable(texture_id, _coordinate),  // deberia ser lanzado desde la posicion del player
        Directionable(_direction),
        range_tiles(_range_tiles),
        state(ProjectileState::ALIVE),
        shooter_id(_shooter_id)
        {}

void Projectile::update(GameLogic& game_logic) { (void)game_logic; }

uint8_t Projectile::get_shooter_id(){ return shooter_id;}

bool Projectile::is_dead(){ return state == ProjectileState::DEAD; }

void Projectile::die(){ state = ProjectileState::DEAD;}

void Projectile::collision_surface(Positionable& surface, GameLogic& game_logic){
    (void)surface;
    (void)game_logic;
    die();
}

// void Projectile::handle_collision(Collidable& other, GameLogic& game_logic) override{
//     std::cout << "handle_sollision equippable" << std::endl;
//     other.on_collision_with(*this, game_logic);    
// };

// void Projectile::on_collision_with(Collidable& other, GameLogic& game_logic) {  
//     other.on_collision_with(*this, game_logic); 
// }

// void Projectile::on_collision_with(Player& player, GameLogic& game_logic) { 
//     std::cout << "Collision Projectile con player" << std::endl;
//     if (shooter_id != player.get_id()) {
//         player.die(game_logic);
//         die();
//     }
// }

// void Projectile::on_collision_with(Ground& ground, GameLogic& game_logic) { 
//     std::cout << "Collision Projectile con ground" << std::endl;
//     (void)ground; 
//     (void)game_logic;
// }

// void Projectile::on_collision_with(Box& box, GameLogic& game_logic) { 
//     std::cout << "Collision Projectile con box" << std::endl;
//     (void)box; 
//     (void)game_logic;
// }


void Projectile::handle_collision_box(Box& box, GameLogic& game_logic){
    (void)game_logic;
    if(!box.is_open()){
        std::cout << "Bala choco con una caja" << std::endl;
        die();
    }
}
