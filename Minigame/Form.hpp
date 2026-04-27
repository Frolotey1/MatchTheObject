#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <memory>

class Form {
	enum class Shapes;
	Shapes shape;
	std::string name;
public:
	enum class Shapes {
		Circle = 0, Triangle = 1, Square = 2, Star = 3, Rectangle = 4,Trapezoid = 5
	};
	explicit Form(Shapes get_shape) : shape(get_shape) {
		switch (shape) {
		case Shapes::Circle:
			name = "Circle";
			break;
		case Shapes::Triangle:
			name = "Triangle";
			break;
		case Shapes::Square:
			name = "Triangle";
			break;
		case Shapes::Star:
			name = "Star";
			break;
		case Shapes::Rectangle:
			name = "Rectangle";
			break;
		case Shapes::Trapezoid:
			name = "Trapezoid";
			break;
		}
	}
	std::string get_name() const { return this->name; }
	Shapes get_shape() const { return this->shape; }

	virtual bool operator==(const Form& rso) const {
		return shape == rso.shape;
	}
	virtual bool IsEqual(const Form& rso) const {
		return *this == rso;
	}
};

#endif