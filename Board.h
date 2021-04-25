#ifndef MENSCH_BOARD_H
#define MENSCH_BOARD_H

#include <vector>
#include <unordered_map>
#include "Piece.h"
#include "Circle.h"

using namespace std;

class Board {
public:
    explicit Board(vector<ColorModel *>);

    vector<Circle *> getCirclesByColor(Color);

    vector<Piece *> getPiecesByColor(Color);

    bool isCircleHomeRow(Circle *circle);

    vector<Color> getColors();

    Color getNextColor(Color color);

    ~Board();

private:
    unordered_map<Color, vector<Circle *>> circlesMap_;
    unordered_map<Color, vector<Piece *>> piecesMap_;
    vector<ColorModel *> colorModels_;
    vector<Color> colors_;
};

#endif //MENSCH_BOARD_H
