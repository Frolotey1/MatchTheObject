#include "../include/Sceen.hpp"
#include "../include/GameActions.hpp"

int Sceen::get_points_for_level() const {
    switch (difficulty) {
    case DifficultyLevel::EASY:
        return 10;
    case DifficultyLevel::MEDIUM:
        return 20;
    case DifficultyLevel::HARD:
        return 50;
    }
    return 10;
}

void Sceen::set_message(const std::string& msg) {
    last_message = msg;
}

Sceen::Sceen(DifficultyLevel diff)
    : difficulty(diff), points_per_success(get_points_for_level()) {}

void Sceen::start() {
    update_available_actions();
}

bool Sceen::is_game_over() const {
    return player.is_inventory_empty();
}

const Player& Sceen::get_player() const {
    return player;
}

Player& Sceen::get_player() {
    return player;
}

const Panel& Sceen::get_panel() const {
    return panel;
}

Panel& Sceen::get_panel() {
    return panel;
}

std::string Sceen::get_last_message() const {
    return last_message;
}

int Sceen::get_points_per_success() const {
    return points_per_success;
}

void Sceen::update_available_actions() {
    action_menu.clear();

    if (player.has_selected_toy()) {
        for (std::size_t i = 0; i < panel.get_frames_count(); ++i) {
            action_menu.add_action(std::make_unique<PlaceToyAction>(i));
        }
    } else {
        for (std::size_t i = 0; i < player.get_inventory_size(); ++i) {
            action_menu.add_action(std::make_unique<SelectToyAction>(i));
        }
    }
}

void Sceen::process_user_action(std::size_t index) {
    if (index >= 0 && index < action_menu.size()) {
        action_menu.execute(index, *this);
    } else {
        set_message("неверный выбор");
    }
}

std::vector<std::string> Sceen::get_action_descriptions() const {
    std::vector<std::string> desc;
    for (size_t i = 0; i < action_menu.size(); ++i) {
        desc.push_back(action_menu.get_description(i));
    }
    return desc;
}

void Sceen::execute_select_toy(std::size_t index) {
    if (player.select_toy(index)) {
        set_message("Взята игрушка: " + player.get_selected_toy().get_name());
    } else {
        set_message("Игрушка не найдена");
    }
    update_available_actions();
}

void Sceen::execute_place_toy(std::size_t frame_index) {
    if (!player.has_selected_toy()) {
        set_message("Нет выбранной игрушки");
        update_available_actions();
        return;
    }

    const Toys& toy = player.get_selected_toy();

    if (panel.try_place_toy(toy, frame_index)) {
        player.add_points(points_per_success);
        player.consume_selected_toy();
        set_message("Успех! +" + std::to_string(points_per_success) + " очков");
    } else {
        set_message("Игрушка не подходит");
        player.deselect_toy();
    }
    update_available_actions();
}

void Sceen::execute_deselect_toy() {
    player.deselect_toy();
    set_message("Выбор отменён");
    update_available_actions();
}
