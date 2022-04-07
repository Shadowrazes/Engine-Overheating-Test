#include "Engine.h"

using namespace std;

Engine::Engine(float _boost, float _overheatTemp, float _coolingCoef, float _temperature, float _envrmntTemp):
    boost(_boost), overheatTemp(_overheatTemp), coolingCoef(_coolingCoef), temperature(_temperature), EnvrmntTemp(_envrmntTemp)
{
    
}

Engine::~Engine() {

}

float Engine::GetBoost() {
    return boost;
}

float Engine::GetCoolingCoef() {
    return coolingCoef;
}

float Engine::GetOverheatTemp() {
    return overheatTemp;
}

float Engine::GetTemperature() {
    return temperature;
}