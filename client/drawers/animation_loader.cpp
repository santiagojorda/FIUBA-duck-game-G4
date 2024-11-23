#include "animation_loader.h"

std::map<std::string, Animation> AnimationLoader::load_animations(const std::string& file_path) {
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

        std::cout << "state_name" << state_name << "\n";
        animations[state_name] = Animation(frames);
    }

    return animations;
}
