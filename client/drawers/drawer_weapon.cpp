#include "drawer_weapon.h"


#include "../../common/weapons_id.h"

#define WEAPON_INITIAL_X 1
#define WEAPON_INITIAL_Y 47

#define SIZE_WEAPON_SPRITE 32
#define TILE_SIZE_WEAPON 10


DrawerWeapon::DrawerWeapon(SDL2pp::Renderer& renderer, const sprite_t& weapon):
        texture(renderer,
                weapon_properties[static_cast<TextureID>(weapon.id_texture)].texturePath) {}

void DrawerWeapon::draw(SDL2pp::Renderer& renderer, const sprite_t& weapon) {
    auto& properties = weapon_properties[static_cast<TextureID>(weapon.id_texture)];

    static std::map<TextureID, std::string> textures = {
            {TextureID::GRANATE, DATA_PATH "/DuckGame-Grenades.png "},    // ok
            {TextureID::BANANA, DATA_PATH "/DuckGame-Grenades.png "},     // ok
            {TextureID::PEW_PEW_LASER, DATA_PATH "/DuckGame-Laser.png"},  // ok
            {TextureID::LASER_RIFLE, DATA_PATH "/DuckGame-Laser.png"},    // ok
            {TextureID::AK_47, DATA_PATH "/DuckGame-MachineGuns.png"},    // ok
            {TextureID::DUELING_GUN,
             DATA_PATH "/DuckGame-Pistol.png"},  // ????????? supongo que es la pistol
            {TextureID::COWBOY_GUN, DATA_PATH "/DuckGame-Pistol.png"},  // ok
            {TextureID::MAGNUM, DATA_PATH "/DuckGame-Pistol.png"},          // ok
            {TextureID::SHOTGUN, DATA_PATH "/DuckGame-Props.png"},
            {TextureID::SNIPER, DATA_PATH "/DuckGame-MoreWeapons.png"}  // ok
    };

    renderer.Copy(
            texture,
            SDL2pp::Rect(properties.src_x, properties.src_y, properties.width, properties.height),
            SDL2pp::Rect(weapon.coordinate.get_x(), weapon.coordinate.get_y(), TILE_SIZE_WEAPON,
                         TILE_SIZE_WEAPON));
}
