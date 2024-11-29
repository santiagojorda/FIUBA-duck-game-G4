#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "../../common/coordinate.h"
#include "../attributes/positionable.h"
#include "../map/map.h"
class Player;
// #include "../player/player.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 500
#define IS_TOUCHING_FLOOR true
const int G_FORCE = 10;

class GamePhysics {
private:
    Map& map;

public:
    GamePhysics(Map& _map);
    bool is_player_out_of_map(Player& player);
    std::shared_ptr<Positionable> get_player_floor_collision(Player& player);

    bool exist_collision(const Rectangle& a, const Rectangle& b);

    void falling(Positionable& target, uint iter_frame);

    ~GamePhysics();
};


#endif  // GAME_PHYSICS_H