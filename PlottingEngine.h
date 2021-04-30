#ifndef MENSCH_PLOTTINGENGINE_H
#define MENSCH_PLOTTINGENGINE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "ColorModel.h"

using namespace std;

class PlottingEngine {
public:
    static void plot(const std::string &fileName, const vector<Color> &colors, unordered_map<Color, vector<int>> &data,
                     vector<double> &times);

};

#endif //MENSCH_PLOTTINGENGINE_H
