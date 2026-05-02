#ifndef TOYS_HPP
#define TOYS_HPP
#include "Form.hpp"
#include <string>

class Toys {
private:
    Form form;
    std::string name;

public:
    explicit Toys(const Form& get_form) : form(get_form), name(get_form.get_name()) {}

    const Form& get_form() const { return form; }
    std::string get_name() const { return name; }
};

#endif
