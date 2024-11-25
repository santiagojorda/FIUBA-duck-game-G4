#ifndef ANIMATION_WEAPON_H
#define ANIMATION_WEAPON_H

#include <string>
#include <vector>

#include <SDL2pp/Rect.hh>

#include "animation.h"

struct properties_t {
    int offset_right_x, offset_left_x, offset_y, scale_width, scale_height;
};

class AnimationWeapon: public Animation {
private:
    std::string path;
    properties_t props;

public:
    AnimationWeapon() = default;

    AnimationWeapon(const std::vector<Frame>& frames, std::string path, properties_t props);

    std::tuple<int, int, int, int, int> get_render_config() const;

    std::string get_path() const;
};

#endif  // ANIMATION_WEAPON_H
