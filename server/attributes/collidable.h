#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <cstdint>
#include <memory>
#include <iostream>

class GameLogic;
class Player;
class Equippable;
class Positionable;
class Ground;
class Banana;
class Box;
class Projectile;

class Collidable : public std::enable_shared_from_this<Collidable> {
public:
    // Método puro que manejará la colisión con otros Collidables
    virtual void handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) = 0;

    // Métodos virtuales para manejar las colisiones con tipos específicos de objetos
    virtual void on_collision_with(Player& player, GameLogic& game_logic);
    virtual void on_collision_with(std::shared_ptr<Equippable> equip, GameLogic& game_logic);
    virtual void on_collision_with(std::shared_ptr<Ground> surface, GameLogic& game_logic);
    virtual void on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic);
    virtual void on_collision_with(std::shared_ptr<Box> box, GameLogic& game_logic);
    virtual void on_collision_with(std::shared_ptr<Banana> banana, GameLogic& game_logic);

    // Destructor virtual
    virtual ~Collidable() = default;
};

#endif // COLLIDABLE_H
