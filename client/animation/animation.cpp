#include "animation.h"

Animation::Animation(const std::vector<Frame>& frames): frames(frames) {}

SDL2pp::Rect Animation::get_current_frame(int _frame) const {
    if (_frame < 0 || static_cast<std::size_t>(_frame) >= frames.size()) {
        throw std::out_of_range("Frame index out of range");
    }

    const Frame& frame = this->frames[_frame];
    return SDL2pp::Rect(frame.x, frame.y, frame.w, frame.h);
}
