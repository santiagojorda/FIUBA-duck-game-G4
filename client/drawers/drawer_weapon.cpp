#include "drawer_weapon.h"

#include "../../common/weapons_id.h"

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE_WEAPON 50
#define UNIQUE_FRAME 0

DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer, uint8_t texture_id):
        Drawable<AnimationWeapon>(renderer), type_weapon("") {
    this->animations =
            AnimationLoader::load_animations<AnimationWeapon>(ANIMATION_PATH "/weapon.yaml");
    this->type_weapon = textures_weapons[static_cast<WeaponTextureID>(texture_id)];
    std::string texture_weapon = this->animations[this->type_weapon].get_path();
    this->texture = std::make_unique<SDL2pp::Texture>(renderer, DATA_PATH + texture_weapon);
}


void DrawerWeapon::draw(const sprite_t& weapon) {
    // auto offset_x, offset_y, _scale_width, _scale_height = get_render_config();
    this->coordenada_x = weapon.coordinate.get_x();
    this->coordenada_y = weapon.coordinate.get_y();
    this->scale_width = TILE_SIZE_WEAPON;
    this->scale_height = TILE_SIZE_WEAPON;
    auto anim = this->animations[this->type_weapon].get_current_frame(UNIQUE_FRAME);
    render(anim);
}
