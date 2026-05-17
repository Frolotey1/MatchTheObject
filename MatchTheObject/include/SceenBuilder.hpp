#ifndef SCEENBUILDER_HPP
#define SCEENBUILDER_HPP

#include "Sceen.hpp"
#include "Form.hpp"
#include <memory>

class SceenBuilder {
private:
    DifficultyLevel difficulty = DifficultyLevel::EASY;
    std::vector<Form::Shapes> frame_shapes;
    std::vector<Form::Shapes> toy_shapes;

public:
    SceenBuilder& set_difficulty(DifficultyLevel diff) {
        difficulty = diff;
        return *this;
    }

    SceenBuilder& add_frame(Form::Shapes shape) {
        frame_shapes.push_back(shape);
        return *this;
    }

    SceenBuilder& add_toy(Form::Shapes shape) {
        toy_shapes.push_back(shape);
        return *this;
    }

    std::unique_ptr<Sceen> build() {
        auto sceen = std::make_unique<Sceen>(difficulty);

        for (auto shape : frame_shapes) {
            Form form(shape);
            Frames frame(form);
            sceen->get_panel().add_frame(frame);
        }

        for (auto shape : toy_shapes) {
            Form form(shape);
            Toys toy(form);
            sceen->get_player().add_toy(toy);
        }

        return sceen;
    }
};

class SceenDirector {
public:
    static std::unique_ptr<Sceen> createTutorialLevel() {
        return SceenBuilder()
        .set_difficulty(DifficultyLevel::EASY)
            .add_frame(Form::Shapes::Circle)
            .add_frame(Form::Shapes::Square)
            .add_toy(Form::Shapes::Circle)
            .add_toy(Form::Shapes::Square)
            .build();
    }

    static std::unique_ptr<Sceen> createNormalLevel() {
        return SceenBuilder()
        .set_difficulty(DifficultyLevel::MEDIUM)
            .add_frame(Form::Shapes::Circle)
            .add_frame(Form::Shapes::Square)
            .add_frame(Form::Shapes::Triangle)
            .add_toy(Form::Shapes::Circle)
            .add_toy(Form::Shapes::Square)
            .add_toy(Form::Shapes::Triangle)
            .add_toy(Form::Shapes::Star)
            .build();
    }

    static std::unique_ptr<Sceen> createHardLevel() {
        return SceenBuilder()
        .set_difficulty(DifficultyLevel::HARD)
            .add_frame(Form::Shapes::Circle)
            .add_frame(Form::Shapes::Square)
            .add_frame(Form::Shapes::Triangle)
            .add_frame(Form::Shapes::Star)
            .add_frame(Form::Shapes::Rectangle)
            .add_toy(Form::Shapes::Circle)
            .add_toy(Form::Shapes::Square)
            .add_toy(Form::Shapes::Triangle)
            .add_toy(Form::Shapes::Star)
            .add_toy(Form::Shapes::Rectangle)
            .add_toy(Form::Shapes::Trapezoid)
            .build();
    }
};

#endif
