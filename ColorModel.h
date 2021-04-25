#ifndef MENSCH_COLORMODEL_H
#define MENSCH_COLORMODEL_H

enum Color {
    Blue, Green, Yellow, Red
};

class ColorModel {
public:
    explicit ColorModel(Color);

    Color getColor();

private:
    Color color_;
};

#endif //MENSCH_COLORMODEL_H
