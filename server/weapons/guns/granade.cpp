#include "granade.h"

#define TICK_FOR_EXPLOTION 120 // 30 frames * 4 secodds 

#define MAX_RANGE_TILES 1
#include "../../game/game_logic.h"
#define DAMAGE 3
#include "../../player/inventory.h"
// #include "../projectiles/granade_projectile.h"

gun_config granade_config = {WeaponTextureID::GRANATE, 1, ShootingRecoil::NONE,
                             ProjectileRange::MEDIUM,  1, 1};

Granade::Granade(const Coordinate& _coordinate): Gun(granade_config, _coordinate) {}

void Granade::update(GameLogic& game_logic){
    if(!is_countdown_enabled){
        return;
    }
    tick++;
    if(tick % TICK_FOR_EXPLOTION == 0){
        game_logic.explote(*this);
        tick = 0;
    }
    
}

void Granade::trigger(ListProjectiles& projectiles, const uint8_t& player_id) {
    Gun::trigger(projectiles, player_id);
    is_countdown_enabled = true;
}

void Granade::trigger_out(ListProjectiles& projectiles, const uint8_t& player_id, bool& was_dropped) {
    Gun::trigger_out(projectiles,player_id, was_dropped);
    was_dropped = true;
}

void Granade::handle_explotion(GameLogic& game_logic){
    game_logic.do_explotion(*this);
    die();
}

void Granade::handle_equip(Inventory& inventory) { 
    if(is_countdown_enabled){
        (void)inventory; 
        return;
    }
    Gun::handle_equip(inventory);
};



Granade::~Granade() {}
