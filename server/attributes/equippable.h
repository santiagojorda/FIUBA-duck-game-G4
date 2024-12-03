#ifndef EQUIPPABLE
#define EQUIPPABLE

#include <cstdint>
#include <memory>
#include "positionable.h"
#include "../../common/coordinate.h"
#include "collidable.h"

class Inventory;
class GameLogic;
class Player;
class Projectile;
enum class EquippableState: uint8_t {
    DEAD,
    ALIVE,
};

class Equippable: public Positionable, public Collidable{
private:
    EquippableState state;
    uint8_t frame;
public:
    Equippable(){}

    Equippable(const uint8_t _texture_id) : Positionable(_texture_id) {}
    explicit Equippable(const uint8_t& _texture_id, const Coordinate& _coordinate) 
        : Positionable(_texture_id, _coordinate), state(EquippableState::ALIVE), frame(0) {}
    virtual void update(GameLogic& game_logic) { (void)game_logic; }

    virtual void handle_equip(Inventory& inventory) = 0;

    void handle_collision(std::shared_ptr<Collidable> other, GameLogic& game_logic) override{
        std::cout << "handle_sollision equippable" << std::endl;
        other->on_collision_with(std::dynamic_pointer_cast<Equippable>(shared_from_this()), game_logic);    
    };
    // virtual void on_collision_with(Player& other, GameLogic& game_logic) override = 0;
    using Collidable::on_collision_with;
    virtual void on_collision_with(Player& player, GameLogic& game_logic) override;
    virtual void on_collision_with(std::shared_ptr<Projectile> projectile, GameLogic& game_logic) override;
    void die(){ state = EquippableState::DEAD; }
    bool is_dead() { return state == EquippableState::DEAD;}
    virtual uint8_t send_frame() { return frame; } 
    virtual std::shared_ptr<Equippable> clone() const = 0;
    virtual ~Equippable() {}
};

#endif
