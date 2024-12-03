#ifndef COLLIDABLE
#define COLLIDABLE

#include <cstdint>
#include <memory>
#include <iostream>

class GameLogic;
class Player;
class Equippable;

class Collidable {
public:    
    virtual void handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) = 0;


    // virtual void on_collision_with(Collidable& other, GameLogic& game_logic) {
    //     other.on_collision_with(*this);
    //     (void)other;
    //     (void)game_logic;   
    // };
    virtual void on_collision_with(Player& player, GameLogic& game_logic) {
        (void)player;
        (void)game_logic;   
    };
    virtual void on_collision_with(std::shared_ptr<Equippable> equip, GameLogic& game_logic) {
        (void)equip;
        (void)game_logic;   
    };

    virtual ~Collidable() = default;
};

#endif
