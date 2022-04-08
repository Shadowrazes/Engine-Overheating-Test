#pragma once

#include <vector>
#include "Engine.h"
#include "LineFunc.h"

namespace EngineTest {

	class ICE : public Engine {					// ДВС

	protected:
		bool isRunning;								// статус двигателя
		double torque;								// текущий крутящий момент
		double crankshaftSpeed;						// текущая скорость вращения коленвала
		double inertMoment;							// момент инерции
		double coefH_m;								// коэффициент зависимости скорости нагрева от крутящего момента
		double coefH_v;								// коэффициент зависимости скорости нагрева от скорости вращения коленвала
		std::vector<Linear::LineFunc> chart;		// кусочные функции зависимости крутящего момента от скорости вращения коленвала
		std::vector<double> temperatureList;		// посекундный отчет температуры

		double HeatingRate();						// скорость нагрева
		double CoolingRate();						// скорость охлаждения
		double FindTorque(const double& x);			// бинарный поиск нужной функции и вычисление от нее крутящего момента 
		void EngineOperation();						// симуляция работы двигателя

	public:
		ICE(double _overheatTemp, double _coolingCoef, double _envrmntTemp, double _inertMoment,
			std::vector<Linear::LineFunc> _chart, double _coefH_m, double _coefH_v);

		void Launch();								// запуск
		void ShutDown();							// остановка
		bool IsRunning();
		double GetTorque();
		double GetCrankshaftSpeed();
		double GetInertMoment();
		double GetCoefH_m();
		double GetCoefH_v();
		std::vector<double> GetTemperatureList();
	};
}

