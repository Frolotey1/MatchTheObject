#ifndef FRAMES_HPP
#define FRAMES_HPP
#include "Form.hpp"
#include "Toys.hpp"

class Frames {
    Form form;
public:
    explicit Frames(const Form& get_form) : form(get_form) {}
    const Form& get_form() const { return form; }
    bool is_passable(const Toys& toy) const { return form.is_equal(toy.get_form()); }
};

#endif
