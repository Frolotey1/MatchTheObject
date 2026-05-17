#ifndef SCEEN_HPP
#define SCEEN_HPP

#include "Player.hpp"
#include "Panel.hpp"
#include "ActionMenu.hpp"
#include <string>
#include <vector>

enum class DifficultyLevel {
    EASY,
    MEDIUM,
    HARD
};

class Sceen {
private:
    Player player;
    Panel panel;
    ActionMenu action_menu;
    DifficultyLevel difficulty;
    int points_per_success;
    std::string last_message;

    int get_points_for_level() const;
    void set_message(const std::string& msg);

public:
    explicit Sceen(DifficultyLevel diff);

    void start();
    bool is_game_over() const;

    const Player& get_player() const;
    Player& get_player();

    const Panel& get_panel() const;
    Panel& get_panel();

    std::string get_last_message() const;
    int get_points_per_success() const;

    void update_available_actions();
    void process_user_action(std::size_t index);

    std::vector<std::string> get_action_descriptions() const;

    void execute_select_toy(std::size_t index);
    void execute_place_toy(std::size_t frame_index);
    void execute_deselect_toy();
};

#endif
