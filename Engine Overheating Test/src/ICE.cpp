#include "../include/ICE.h"
#include <chrono>
#include <cmath>
#include <future>

namespace EngineTest {
	ICE::ICE(double _overheatTemp, double _coolingCoef, double _envrmntTemp, double _inertMoment,
		std::vector<Linear::LineFunc> _chart, double _coefH_m, double _coefH_v) : Engine(_overheatTemp, _coolingCoef, _envrmntTemp)
	{
		isRunning = false;
		torque = 20;
		inertMoment = _inertMoment;
		boost = torque / inertMoment;
		temperature = _envrmntTemp;
		chart = _chart;
		coefH_m = _coefH_m;
		coefH_v = _coefH_v;
	}

	double ICE::HeatingRate() {
		return inertMoment * coefH_m + std::pow(crankshaftSpeed, 2) * coefH_v;
	}

	double ICE::CoolingRate() {
		return coolingCoef * (EnvrmntTemp - temperature);
	}

	double ICE::FindTorque(const double& x) {
		int l = 0;
		int r = chart.size() - 1;
		int mid;
		while ((l <= r) ) {
			mid = (l + r) / 2;
			if (x >= chart[mid].GetStart().X && x <= chart[mid].GetEnd().X)
				return chart[mid].Func(x);
			if (chart[mid].GetEnd().X > x) r = mid - 1;
			else l = mid + 1;
		}
		throw std::out_of_range("Going beyond the boundaries of the function");
	}

	void ICE::EngineOperation() {
		while (isRunning) {
			temperatureList.push_back(temperature);
			temperature += HeatingRate() + CoolingRate();
			crankshaftSpeed += boost;
			torque = FindTorque(crankshaftSpeed);
			boost = torque / inertMoment;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		temperatureList.push_back(temperature);
	}

	void ICE::Launch() {
		isRunning = true;
		auto exodus = std::async(&ICE::EngineOperation, this);	 // запуск симуляции и ожидание результата
		exodus.get();
	}

	void ICE::ShutDown() {
		isRunning = false;
	}

	bool ICE::IsRunning() {
		return isRunning;
	}

	double ICE::GetTorque() {
		return torque;
	}

	double ICE::GetCrankshaftSpeed() {
		return crankshaftSpeed;
	}

	double ICE::GetInertMoment() {
		return inertMoment;
	}

	double ICE::GetCoefH_m() {
		return coefH_m;
	}

	double ICE::GetCoefH_v() {
		return coefH_v;
	}

	std::vector<double> ICE::GetTemperatureList() {
		return temperatureList;
	}
}