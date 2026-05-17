#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <memory>

class Form {
public:
    enum class Shapes {
        Circle = 0, Triangle = 1, Square = 2, Star = 3, Rectangle = 4, Trapezoid = 5
    };
private:
    Shapes shape;
    std::string name;
public:
    explicit Form(Shapes get_shape) : shape(get_shape) {
        switch (shape) {
        case Shapes::Circle:
            name = "Circle";
            break;
        case Shapes::Triangle:
            name = "Triangle";
            break;
        case Shapes::Square:
            name = "Square";
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

    std::string get_name() const { return name; }
    Shapes get_shape() const { return shape; }

    bool operator==(const Form& other) const {
        return shape == other.shape;
    }

    bool is_equal(const Form& other) const {
        return *this == other;
    }
};

#endif
