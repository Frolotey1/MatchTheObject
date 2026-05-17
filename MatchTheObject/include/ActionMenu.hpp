#ifndef ACTIONMENU_HPP
#define ACTIONMENU_HPP
#include "Action.hpp"
#include <vector>
#include <memory>
#include <string>

class ActionMenu {
    std::vector<std::unique_ptr<Action>> actions;
public:
    void add_action(std::unique_ptr<Action> action) {
        actions.push_back(std::move(action));
    }
    void clear() { actions.clear(); }
    std::size_t size() const { return actions.size(); }

    std::string get_description(std::size_t index) const {
        if (index < actions.size()) return actions[index]->get_description();
        return "";
    }
    void execute(std::size_t index, Sceen& sceen) {
        if (index < actions.size()) actions[index]->execute(sceen);
    }
};

#endif
