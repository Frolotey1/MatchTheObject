#ifndef GAME_APPLICATION_HPP
#define GAME_APPLICATION_HPP

#include "Sceen.hpp"
#include "SceenBuilder.hpp"
#include "ConsoleUI.hpp"

class GameApplication {
private:
    ConsoleUI ui;
    std::unique_ptr<Sceen> game;

    void show_welcome() {
        ui.show_message("Демонстрация работы игры");
    }

    void show_difficulty_menu() {
        ui.show_message("Уровни сложности:");
        ui.show_message("1. Лёгкий (10 очков)");
        ui.show_message("2. Средний (20 очков)");
        ui.show_message("3. Сложный (50 очков)");
    }

    DifficultyLevel choose_difficulty() {
        int choice = ui.get_choice(3);
        switch (choice) {
        case 0:
            return DifficultyLevel::EASY;
        case 1:
            return DifficultyLevel::MEDIUM;
        default:
            return DifficultyLevel::HARD;
        }
    }

    void create_game(DifficultyLevel diff) {
        switch (diff) {
        case DifficultyLevel::EASY:
            game = SceenDirector::createTutorialLevel();
            ui.show_message("Лёгкий уровень");
            break;
        case DifficultyLevel::MEDIUM:
            game = SceenDirector::createNormalLevel();
            ui.show_message("Средний уровень");
            break;
        case DifficultyLevel::HARD:
            game = SceenDirector::createHardLevel();
            ui.show_message("Сложный уровень");
            break;
        }
    }

    void show_game_state() {
        ui.show_message("Счёт: " + std::to_string(game->get_player().get_score()));
        ui.show_message("Игрушек осталось: " + std::to_string(game->get_player().get_inventory_size()));
        if (game->get_player().has_selected_toy()) {
            ui.show_message("В руке: " + game->get_player().get_selected_toy().get_name());
        } else {
            ui.show_message("Рука пуста");
        }
    }

    void show_result() {
        std::string msg = game->get_last_message();
        if (!msg.empty()) ui.show_message(msg);
    }

    void show_game_end() {
        ui.show_message("Завершение игры");
        ui.show_message("Финальный счет: " + std::to_string(game->get_player().get_score()));
    }

public:
    GameApplication() = default;

    void run() {
        show_welcome();
        show_difficulty_menu();
        DifficultyLevel diff = choose_difficulty();
        create_game(diff);

        game->start();

        while (!game->is_game_over()) {
            game->update_available_actions();
            show_game_state();

            auto actions = game->get_action_descriptions();
            ui.show_actions(actions);

            int choice = ui.get_choice(actions.size());
            game->process_user_action(choice);
            show_result();
        }

        show_game_end();
    }
};

#endif
