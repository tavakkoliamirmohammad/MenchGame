#ifndef MENSCH_COLORMODEL_H
#define MENSCH_COLORMODEL_H
#include <iostream>

enum class Color {
    Blue, Green, Yellow, Red
};

inline std::ostream &operator<<(std::ostream &os, const Color color) {
    switch (color) {
        case Color::Red :
            return os << "Red";
        case Color::Yellow:
            return os << "Yellow";
        case Color::Green:
            return os << "Green";
        case Color::Blue:
            return os << "Blue";
            // omit default case to trigger compiler warning for missing cases
    };
    return os << "UNDEFINED_COLOR";
}

class ColorModel {
public:
    explicit ColorModel(Color);

    Color getColor();

private:
    Color color_;
};

#endif //MENSCH_COLORMODEL_H
