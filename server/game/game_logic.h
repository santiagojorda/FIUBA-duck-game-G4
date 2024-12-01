#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <list>
#include <memory>

#include "../../common/action_events.h"

#include "../map/map.h"
#include "../player/player.h"
#include "../attributes/equippable.h"
#include "game_physics.h"
class Event;
class ListProjectiles;
class ListPlayers;
class Event;

class GameLogic {
private:
    ListPlayers& players;
    Map& map;
    ListProjectiles& projectiles;
    GamePhysics physics;
    void update_player_equip_collision(Player& player);
    void update_players();
    void update_projectiles();
    void remove_bullet(Bullet& bullet);
public:
    explicit GameLogic(ListPlayers& _players, Map& _map,
                       ListProjectiles& _projectiles);
    void handle_event(Event& event);
    void update();
    ListProjectiles& get_projectiles();
    GamePhysics& get_physics();
    void handle_drop(std::shared_ptr<Equippable> item);
    Player& get_player(const uint8_t& player_id);
    void fall(Player& player);
    void move(Player& player, int x, int y);
    void move_horizontal(Player& player, Direction& direction);
    void move(Bullet& bullet, int x, int y);
    void update_player_gravity(Player& player);

    ~GameLogic();
};

#endif
