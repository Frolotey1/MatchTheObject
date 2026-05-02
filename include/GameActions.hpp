#ifndef GAMEACTIONS_HPP
#define GAMEACTIONS_HPP

#include "Action.hpp"

class SelectToyAction : public Action {
private:
    std::size_t toy_index;
public:
    explicit SelectToyAction(std::size_t index) : toy_index(index) {}
    std::string get_description() const override;
    void execute(Sceen& sceen) override;
};

class PlaceToyAction : public Action {
private:
    std::size_t frame_index;
public:
    explicit PlaceToyAction(std::size_t index) : frame_index(index) {}
    std::string get_description() const override;
    void execute(Sceen& sceen) override;
};

class DeselectToyAction : public Action {
public:
    std::string get_description() const override;
    void execute(Sceen& sceen) override;
};

#endif
