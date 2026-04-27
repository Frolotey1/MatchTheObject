#ifndef TOYS_HPP
#define TOYS_HPP 
#include "Form.hpp"

class Toys {
private:
	std::string name;
	std::unique_ptr<Form> form;
public:
	explicit Toys(const Form& get_form) : form(std::make_unique<Form>(get_form)) {}
	const Form& get_form() const { return *form; }
	bool is_same(const Toys& other) const {return this == &other;}
};
#endif