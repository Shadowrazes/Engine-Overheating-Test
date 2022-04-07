#pragma once

class Engine{ // общий класс для всех двигателей

protected:
	float boost;  // ускорение
	float overheatTemp; // температура перегрева
	float coolingCoef;  // коэффициент охлаждения
	float temperature;  // температура двигателя

public:
	float EnvrmntTemp; // температура окружающей среды

	Engine(float _boost, float _overheatTemp, float _coolingCoef, float _temperature, float _envrmntTemp);
	virtual ~Engine();

	virtual float HeatingRate() = 0; // скорость нагрева
	virtual float CoolingRate() = 0; // скорость охлаждения

	virtual float GetBoost();
	virtual float GetOverheatTemp();
	virtual float GetCoolingCoef();
	virtual float GetTemperature();
};

