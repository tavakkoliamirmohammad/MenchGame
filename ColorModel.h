#ifndef MENSCH_COLORMODEL_H
#define MENSCH_COLORMODEL_H

enum class Color {
    Green, Red, Blue, Yellow
};

class ColorModel {
public:
    explicit ColorModel(Color);

    Color getColor();

private:
    Color color_;
};

#endif //MENSCH_COLORMODEL_H
