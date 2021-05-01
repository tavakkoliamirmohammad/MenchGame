#ifndef MENSCH_PLOTTINGENGINE_H
#define MENSCH_PLOTTINGENGINE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "ColorModel.h"

using namespace std;

class PlottingEngine {
public:
    PlottingEngine(int width, int height);

    void cumulativePlot(const std::string &name, const std::string &ytitle, const vector<Color> &colors,
                        unordered_map<Color, vector<int>> &data,
                        vector<double> &times) const;

    void windowedPlot(const std::string &name, const std::string &ytitle, const vector<Color> &colors,
                      unordered_map<Color, vector<int>> &data,
                      vector<double> &times, int interval) const;

private:
    int width_, height_;

};

#endif //MENSCH_PLOTTINGENGINE_H
