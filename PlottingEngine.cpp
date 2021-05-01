#include <sstream>
#include <algorithm>
#include <iterator>
#include "matplotlibcpp.h"
#include "PlottingEngine.h"

namespace plt = matplotlibcpp;


PlottingEngine::PlottingEngine(int width, int height) : height_(height), width_(width) {

}


void PlottingEngine::cumulativePlot(const std::string &name, const std::string &ytitle, const vector<Color> &colors,
                                    unordered_map<Color, vector<int>> &data, vector<double> &times) const {
    plt::figure_size(width_, height_);
    for (auto color: colors) {
        vector<int> processedData;
        for (auto d : data[color]) {
            processedData.push_back(d);
        }
        for (int i = 1; i < processedData.size(); ++i) {
            processedData[i] = processedData[i - 1] + processedData[i];
        }
        stringstream ss;
        ss << "Player " << color;
        plt::named_plot(ss.str(), times, processedData);
    }
    plt::title(name);
    plt::ylabel(ytitle);
    plt::xlabel("time(s)");
    plt::legend();
    plt::save("./outputs/cumulative_" + name + ".png");

}

void PlottingEngine::windowedPlot(const string &name, const string &ytitle, const vector<Color> &colors,
                                  unordered_map<Color, vector<int>> &data, vector<double> &times, int interval) const {
    plt::figure_size(width_, height_);
    for (auto color: colors) {
        vector<double> processedTime;
        vector<int> processedData;
        int currentTimeIndex = 0;
        int currentValue = 0;
        double baseTime = 0;
        while (baseTime < times[times.size() - 1]) {
            while (abs(baseTime - times[currentTimeIndex]) < interval) {
                currentValue += data[color][currentTimeIndex];
                ++currentTimeIndex;
            }
            processedData.push_back(currentValue);
            processedTime.push_back(baseTime + interval);
            currentValue = 0;
            baseTime = baseTime + interval;
        }
        stringstream ss;
        ss << "Player " << color;
        plt::named_plot(ss.str(), processedTime, processedData);
    }
    plt::title(name);
    plt::ylabel(ytitle);
    plt::xlabel("time(s)");
    plt::legend();
    plt::save("./outputs/window_" + name + ".png");
}
