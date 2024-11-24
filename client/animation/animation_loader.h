#ifndef ANIMATION_LOADER_H
#define ANIMATION_LOADER_H

#include <map>
#include <string>

#include <yaml-cpp/yaml.h>

#include "animation.h"
#include "animation_weapon.h"

class AnimationLoader {
public:
    template <typename T>
    static std::map<std::string, T> load_animations(const std::string& file_path);
};

#endif  // ANIMATION_LOADER_H
