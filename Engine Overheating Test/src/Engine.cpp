#include "include/Engine.h"

namespace EngineTest {

    Engine::Engine(double _overheatTemp, double _coolingCoef, double _envrmntTemp) :
        overheatTemp(_overheatTemp), coolingCoef(_coolingCoef), EnvrmntTemp(_envrmntTemp)
    {
        boost = 0;
        temperature = 0;
    }

    Engine::~Engine() {

    }

    double Engine::GetBoost() {
        return boost;
    }

    double Engine::GetCoolingCoef() {
        return coolingCoef;
    }

    double Engine::GetOverheatTemp() {
        return overheatTemp;
    }

    double Engine::GetTemperature() {
        return temperature;
    }
}