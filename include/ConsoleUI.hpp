#ifndef CONSOLEUI_HPP
#define CONSOLEUI_HPP

#include "GameUI.hpp"
#include <iostream>
#include <limits>

class ConsoleUI : public GameUI {
public:
    void show_message(const std::string& msg) override {
        std::cout << msg << std::endl;
    }

    void show_actions(const std::vector<std::string>& actions) override {
        std::cout << "Действия:\n";
        for (std::size_t i = 0; i < actions.size(); ++i) {
            std::cout << "  " << i + 1 << ". " << actions[i] << "\n";
        }
    }
    int get_choice(int max_choice) override {
        int choice;
        std::cout << "Выбор от 1 до " << max_choice << ": ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice - 1;
    }
};

#endif
