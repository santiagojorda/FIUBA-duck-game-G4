#include "animation_weapon.h"

AnimationWeapon::AnimationWeapon(const std::vector<Frame>& frames, std::string path,
                                 properties_t props):
        Animation(frames), path(path), props(props) {}

std::tuple<int, int, int, int> AnimationWeapon::get_render_config() const {
    return std::make_tuple(props.offset_x, props.offset_y, props.scale_width, props.scale_height);
}

std::string AnimationWeapon::get_path() const { return path; }
