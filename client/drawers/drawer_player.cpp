#include "drawer_player.h"

#include <map>

#include "../../common/direction.h"
#include "../../common/weapons_id.h"
#include "../game_state/player.h"

DrawerPlayer::DrawerPlayer(SDL2pp::Renderer& renderer, uint8_t texture_id,
                           std::map<std::string, Animation>& animations,
                           std::map<std::string, Animation>& animation_weapon,
                           std::map<std::string, Animation>& animation_armor):
        Drawable(renderer, animations),
        animation_weapon(animation_weapon),
        animation_armor(animation_armor) {
    std::string path =
            this->texture_provider.get_duck_texture(static_cast<TextureDucks>(texture_id));
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, path);
}

void DrawerPlayer::draw(const player_t& player) {
    this->flip = static_cast<Direction>(player.is_looking) == Direction::LEFT;
    this->coordenada_x = player.sprite.coordinate.get_x();
    this->coordenada_y = player.sprite.coordinate.get_y() - OFFSET_Y_DUCK;
    this->scale_height = TILE_SIZE;
    this->scale_width = TILE_SIZE;
    this->frame = static_cast<int>(player.frame);
    this->type_animation =
            texture_provider.get_duck_action_texture(static_cast<DuckStateType>(player.state));
    this->render();

    if (static_cast<int>(player.inventory.weapon) != 0) {
        this->update_weapon(player);
        this->update_wings();
    }

    // this->update_armor(player);
}

void DrawerPlayer::update_weapon(const player_t& player) {
    DrawerWeapon drawer_weapon(this->renderer, player.inventory.weapon, this->animation_weapon);
    drawer_weapon.draw_inventory(player.sprite.coordinate, player.is_looking);
}


void DrawerPlayer::update_armor(const player_t& player) {
    DrawerEquipment drawer_equipment(this->renderer, 1, this->animation_armor);
    drawer_equipment.draw(player, true);
}

void DrawerPlayer::update_helmet(const player_t& player) {
    DrawerEquipment drawer_equipment(this->renderer, 2, this->animation_armor);
    drawer_equipment.draw(player);
}

void DrawerPlayer::update_wings() {
    this->scale_height = TILE_SIZE_ALA;
    this->scale_width = TILE_SIZE_ALA;
    this->coordenada_x += flip ? 16 : 12;
    this->coordenada_y += 15;
    this->type_animation = "wings_weapon";
    render();
}
