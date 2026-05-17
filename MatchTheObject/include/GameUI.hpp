#ifndef GAMEUI_HPP
#define GAMEUI_HPP
#include <string>
#include <vector>

class GameUI {
public:
    virtual ~GameUI() = default;
    virtual void show_message(const std::string& msg) = 0;
    virtual void show_actions(const std::vector<std::string>& actions) = 0;
    virtual int get_choice(int max_choice) = 0;
};

#endif
