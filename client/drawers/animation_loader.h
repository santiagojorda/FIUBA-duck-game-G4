#ifndef ANIMATION_LOADER_H
#define ANIMATION_LOADER_H

#include <map>
#include <string>

#include <yaml-cpp/yaml.h>

#include "animation.h"

class AnimationLoader {
public:
    static std::map<std::string, Animation> load_animations(const std::string& file_path);
};

#endif  // ANIMATION_LOADER_H
