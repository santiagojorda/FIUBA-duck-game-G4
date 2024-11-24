#ifndef ANIMATION_WEAPON_H
#define ANIMATION_WEAPON_H

#include <string>
#include <vector>

#include <SDL2pp/Rect.hh>

#include "animation.h"

class AnimationWeapon: public Animation {
private:
    std::string path;
    int offset_x;
    int offset_y;
    int scale_width;
    int scale_height;

public:
    AnimationWeapon() = default;

    AnimationWeapon(const std::vector<Frame>& frames, std::string path, int offset_x, int offset_y,
                    int scale_width, int scale_height);

    std::tuple<int, int, int, int> get_render_config() const;
};

#endif  // ANIMATION_WEAPON_H
