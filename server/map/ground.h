#ifndef GROUND
#define GROUND

#include <cstdint>

#include "../attributes/positionable.h"
#include "../attributes/collidable.h"

class Projectile;

class Ground: public Positionable{
private:
    uint8_t state;
public:
    explicit Ground(const Coordinate& _coordinate, const uint8_t& _texture_id) : Positionable(_texture_id, _coordinate){}


    // void on_collision_with(Collidable& other, GameLogic& game_logic) override {
    //     other.on_collision_with(*this, game_logic); 
    // }

    // void on_collision_with(Projectile& projectile, GameLogic& game_logic){
    //     std::cout << "Collision ground con projectile" << std::endl;
    //     (void)projectile; 
    //     (void)game_logic;
    // }
    
    // void on_collision_with(Player& player, GameLogic& game_logic){
    //     std::cout << "Collision ground con player" << std::endl;
    //     (void)player; 
    //     (void)game_logic;
    // }
    
    ~Ground() {}
};

#endif