#include "../include/GameActions.hpp"
#include "../include/Sceen.hpp"

std::string SelectToyAction::get_description() const {
    return "Взять игрушку под номером" + std::to_string(toy_index + 1);
}

void SelectToyAction::execute(Sceen& sceen) {
    sceen.execute_select_toy(toy_index);
}

std::string PlaceToyAction::get_description() const {
    return "Разместить в рамку под номером" + std::to_string(frame_index + 1);
}

void PlaceToyAction::execute(Sceen& sceen) {
    sceen.execute_place_toy(frame_index);
}

std::string DeselectToyAction::get_description() const {
    return "Отменить выбор";
}

void DeselectToyAction::execute(Sceen& sceen) {
    sceen.execute_deselect_toy();
}
