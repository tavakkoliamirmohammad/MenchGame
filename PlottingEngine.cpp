#include <sstream>
#include "matplotlibcpp.h"
#include "PlottingEngine.h"

namespace plt = matplotlibcpp;

void PlottingEngine::plot(const std::string &name, const std::string &ytitle, const vector<Color> &colors,
                          unordered_map<Color, vector<int>> &data, vector<double> &times, bool cumulative) {
    plt::figure_size(1200, 780);
    for (auto color: colors) {
        vector<int> processedData = data[color];
        if (cumulative) {
            for (int i = 1; i < processedData.size(); ++i) {
                processedData[i] = processedData[i - 1] + processedData[i];
            }
        }
        stringstream ss;
        ss << "Player " << color;
        plt::named_plot(ss.str(), times, processedData);
    }
    plt::title(name);
    plt::ylabel(ytitle);
    plt::xlabel("time(s)");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./outputs/" + name + ".png");

}