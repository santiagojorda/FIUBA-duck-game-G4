#include "collidable.h"

// Implementación de los métodos virtuales de colisión

void Collidable::on_collision_with(Player& player, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Player
    std::cout << "Collidable collided with Player!" << std::endl;
    (void)player;
    (void)game_logic;
}

void Collidable::on_collision_with(std::shared_ptr<Equippable> equip, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Equippable
    std::cout << "Collidable collided with Equippable!" << std::endl;
    (void)equip;
    (void)game_logic;
}

void Collidable::on_collision_with(std::shared_ptr<Ground> surface, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Ground
    std::cout << "Collidable collided with Ground!" << std::endl;
    (void)surface;
    (void)game_logic;
}

void Collidable::on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Projectile
    std::cout << "Collidable collided with Projectile!" << std::endl;
    (void)projectile;
    (void)game_logic;
}

void Collidable::on_collision_with(std::shared_ptr<Box> box, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Projectile
    std::cout << "Collidable collided with Box!" << std::endl;
    (void)box;
    (void)game_logic;
}


void Collidable::on_collision_with(std::shared_ptr<Banana> banana, GameLogic& game_logic) {
    // Comportamiento por defecto al chocar con un Projectile
    std::cout << "Collidable collided with Banana!" << std::endl;
    (void)banana;
    (void)game_logic;
}