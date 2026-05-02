#ifndef PANEL_HPP
#define PANEL_HPP
#include "Frames.hpp"
#include <vector>

class Panel {
    std::vector<Frames> frames;
public:
    void add_frame(const Frames& frame) { frames.push_back(frame); }
    std::size_t get_frames_count() const { return frames.size(); }
    const Frames& get_frame(size_t index) const { return frames[index]; }

    bool try_place_toy(const Toys& toy, std::size_t frame_index) const {
        if (frame_index >= frames.size()) return false;
        return frames[frame_index].is_passable(toy);
    }
};

#endif
