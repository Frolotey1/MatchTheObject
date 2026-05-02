#ifndef ACTION_HPP
#define ACTION_HPP
#include <string>
class Sceen;

class Action {
public:
    virtual ~Action() = default;
    virtual std::string get_description() const = 0;
    virtual void execute(Sceen& sceen) = 0;
};

#endif
