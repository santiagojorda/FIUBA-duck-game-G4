#include "animation_loader.h"

template <>
std::map<std::string, Animation> AnimationLoader::load_animations<Animation>(
        const std::string& file_path) {
    YAML::Node root = YAML::LoadFile(file_path);
    std::map<std::string, Animation> animations;

    for (const auto& state: root) {
        std::string state_name = state.first.as<std::string>();
        const auto& rects = state.second["rects"];
        std::vector<Frame> frames;

        for (const auto& rect: rects) {
            frames.push_back(Frame{rect["x"].as<int>(), rect["y"].as<int>(), rect["w"].as<int>(),
                                   rect["h"].as<int>()});
        }

        animations[state_name] = Animation(frames);
    }

    return animations;
}

template <>
std::map<std::string, AnimationWeapon> AnimationLoader::load_animations<AnimationWeapon>(
        const std::string& file_path) {
    YAML::Node root = YAML::LoadFile(file_path);
    std::map<std::string, AnimationWeapon> animations;

    for (const auto& state: root) {
        std::string state_name = state.first.as<std::string>();
        const auto& rects = state.second["rects"];
        std::vector<Frame> frames;

        for (const auto& rect: rects) {
            frames.push_back(Frame{rect["x"].as<int>(), rect["y"].as<int>(), rect["w"].as<int>(),
                                   rect["h"].as<int>()});
        }

        int offset_x = state.second["offset_x"].as<int>();
        int offset_y = state.second["offset_y"].as<int>();
        int scale_width = state.second["scale_width"].as<int>();
        int scale_height = state.second["scale_height"].as<int>();

        animations[state_name] =
                AnimationWeapon(frames, offset_x, offset_y, scale_width, scale_height);
    }

    return animations;
}
