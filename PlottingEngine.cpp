#include "matplotlibcpp.h"
#include "PlottingEngine.h"

namespace plt = matplotlibcpp;

void PlottingEngine::plot(const std::string &fileName, const vector<Color> &colors,
                          unordered_map<Color, vector<int>> &data, vector<double> &times) {
    plt::figure_size(1200, 780);
    for (auto color: colors) {
        // Set the size of output image to 1200x780 pixels
        // Plot line from given x and y data. Color is selected automatically.
        plt::plot(data[color], times);
    }
    plt::title("Sample figure");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./output/basic.png");

}