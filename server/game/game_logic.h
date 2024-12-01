#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>
#include <memory>

#include "../../common/action_events.h"

#include "../map/map.h"
#include "../player/player.h"
#include "../attributes/equippable.h"
#include "game_physics.h"
#include "../weapons/projectile_range.h"

class Projectile;
class Gun;
class Event;
class ListProjectiles;
class ListItemsMap;
class ListPlayers;
class Event;

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    ListItemsMap& items;
    ListProjectiles& projectiles;
    GamePhysics physics;
    void update_player_equip_collision(Player& player);
    void update_players();
    void update_weapons();
    void update_projectiles();
    void remove_projectile(std::shared_ptr<Projectile> projectile);
    bool can_move(Player& player, int x, int y);

public:
    explicit GameLogic(ListPlayers& _players, Map& _map, ListItemsMap& _items,
                       ListProjectiles& _projectiles);
    void handle_event(Event& event);
    void update();
    void explote(Gun& gun);
    void do_explotion(Gun& gun);
    ListProjectiles& get_projectiles();
    GamePhysics& get_physics();
    void handle_drop(std::shared_ptr<Equippable> item);
    Player& get_player(const uint8_t& player_id);
    void fall(Player& player);
    void move(Player& player, int x, int y);
    void move_horizontal(Player& player, Direction& direction);
    void move(Projectile& projectile, int x, int y);
    void update_player_gravity(Player& player);

    ~GameLogic();
};

#endif
