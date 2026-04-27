#ifndef FRAMES_HPP
#define FRAMES_HPP
#include "Form.hpp"
#include "Toys.hpp"

class Frames {
private:
	std::unique_ptr<Form> form;
public:
	explicit Frames(const Form& get_form) : form(std::make_unique<Form>(get_form)) {}
	bool IsSame(const Frames& other) {return this == &other;}
	bool IsPassable(const Toys& other) const {
		return form->IsEqual(other.get_form());
	}
	//void Collect(const Toys& other);
};
#endif