#ifndef EQUIPPABLE
#define EQUIPPABLE

#include <cstdint>
#include <memory>
#include "positionable.h"
#include "../../common/coordinate.h"

class Inventory;
class GameLogic;

enum class EquippableState: uint8_t {
    DEAD,
    ALIVE,
};

class Equippable: public Positionable {
private:
    EquippableState state;
public:
    Equippable(){}
    explicit Equippable(const uint8_t& _texture_id, const Coordinate& _coordinate) 
        : Positionable(_texture_id, _coordinate), state(EquippableState::ALIVE) {}
    virtual void update(GameLogic& game_logic) { (void)game_logic; }
    virtual void handle_equip(Inventory& inventory) = 0;
    void die(){ state = EquippableState::DEAD; }
    bool is_dead() { return state == EquippableState::DEAD;}
    virtual std::shared_ptr<Equippable> clone() const = 0;

    virtual ~Equippable() {}
};

#endif
