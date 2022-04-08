#pragma once

namespace EngineTest {
	class Engine {			// общий класс для всех двигателей

	protected:
		double boost;		// ускорение
		double overheatTemp; // температура перегрева
		double coolingCoef;  // коэффициент охлаждения
		double temperature;  // температура двигателя

		virtual double HeatingRate() = 0;	// скорость нагрева
		virtual double CoolingRate() = 0;	// скорость охлаждения
	public:
		double EnvrmntTemp;	// температура окружающей среды

		Engine(double _overheatTemp, double _coolingCoef, double _envrmntTemp);
		virtual ~Engine();

		virtual void Launch() = 0;			// запуск двигателя
		virtual void ShutDown() = 0;		// выключение

		virtual double GetBoost();
		virtual double GetOverheatTemp();
		virtual double GetCoolingCoef();
		virtual double GetTemperature();
	};
}

