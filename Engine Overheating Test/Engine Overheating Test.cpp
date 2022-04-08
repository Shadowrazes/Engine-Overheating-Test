#include <iostream>
#include "ICE.h"
#include "Test.h"
#include <thread>
#include <string>

double inputEnvrmntTemp() {
    while (true) {
        try {
            std::cout << "Input environment temperature: ";
            std::string input;
            std::cin >> input;
            for (const auto& it : input)
                if (!std::isdigit(it))
                    throw std::invalid_argument("A number was expected, but a string was received");
            double envrmntTemp = std::stod(input);
            return envrmntTemp;
        }
        catch(std::exception) {
            std::cout << "Incorrect input, try again" << std::endl;
        }
    }
}

void exodus(EngineTest::ICE& engine, const std::vector<double>& temperatureList, const double& time) {
    int count = 0;
    for (const auto& it : temperatureList) {
        std::cout << ++count << ") " << it << std::endl;
    }

    if (temperatureList.back() >= engine.GetOverheatTemp())
        std::cout << std::endl << "The engine was overheated in " << time << " seconds" << std::endl;
    else
        std::cout << std::endl << "The engine wasn't overheated in " << time << " seconds" << std::endl;
}

int main()
{
    std::vector <Linear::Point> points{ {0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0} };
    std::vector <Linear::LineFunc> funcs;
    for (int i = 0; i < points.size() - 1; i++)
        funcs.push_back(Linear::LineFunc(points[i], points[i + 1]));
    points.clear();
    double I = 10;
    double overheatTemp = 110;
    double H_m = 0.01;
    double H_v = 0.0001;
    double C = 0.1;
    double envrmntTemp = inputEnvrmntTemp();

    EngineTest::ICE engine(overheatTemp, C, envrmntTemp, I, funcs, H_m, H_v);
    EngineTest::Test testArea;

    std::cout << "Testing..." << std::endl;
    double time = testArea.TestICE(engine);
    std::vector<double> temperatureList = engine.GetTemperatureList();
    exodus(engine, temperatureList, time);
}