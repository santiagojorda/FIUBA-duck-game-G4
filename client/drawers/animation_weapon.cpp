#include "animation_weapon.h"

AnimationWeapon::AnimationWeapon(const std::vector<Frame>& frames, int offset_x, int offset_y,
                                 int scale_width, int scale_height):
        Animation(frames),
        offset_x(offset_x),
        offset_y(offset_y),
        scale_width(scale_width),
        scale_height(scale_height) {}


std::tuple<int, int, int, int> AnimationWeapon::get_render_config() const {
    return std::make_tuple(offset_x, offset_y, scale_width, scale_height);
}
