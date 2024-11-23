#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>

#include <SDL2pp/Rect.hh>

struct Frame {
    int x, y, w, h;
};

class Animation {
private:
    std::vector<Frame> frames;

public:
    Animation() = default;

    explicit Animation(const std::vector<Frame>& frames);

    SDL2pp::Rect get_current_frame(int frame) const;
};

#endif  // ANIMATION_H
