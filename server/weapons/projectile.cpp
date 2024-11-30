#include "projectile.h"
// #include "../game/game_physics.h"
#include "../game/game_logic.h"

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
