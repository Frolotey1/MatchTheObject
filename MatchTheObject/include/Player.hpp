#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Toys.hpp"
#include <vector>
#include <memory>
#include <optional>

class Player {
    std::vector<Toys> inventory;
    std::optional<std::size_t> selected_toy_index;
    int score;
public:
    Player() : score(0) {}

    void add_toy(const Toys& toy) { inventory.push_back(toy); }
    std::size_t get_inventory_size() const { return inventory.size(); }
    bool is_inventory_empty() const { return inventory.empty(); }
    int get_score() const { return score; }
    void add_points(int points) { score += points; }

    bool select_toy(std::size_t index) {
        if (index < inventory.size()) {
            selected_toy_index = index;
            return true;
        }
        return false;
    }

    void deselect_toy() { selected_toy_index.reset(); }
    bool has_selected_toy() const { return selected_toy_index.has_value(); }

    const Toys& get_selected_toy() const {
        static Toys toy(Form(Form::Shapes::Circle));
        if (selected_toy_index.has_value()) {
            return inventory[selected_toy_index.value()];
        }
        return toy;
    }
    bool consume_selected_toy() {
        if (!selected_toy_index.has_value()) return false;

        std::size_t index = selected_toy_index.value();
        if (index < inventory.size()) {
            inventory.erase(inventory.begin() + index);
            selected_toy_index.reset();
            return true;
        }
        return false;
    }
};

#endif
