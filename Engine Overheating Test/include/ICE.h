#pragma once

#include <vector>
#include "Engine.h"
#include "LineFunc.h"

namespace EngineTest {

	class ICE : public Engine {						// ���

	protected:
		bool isRunning;								// ������ ���������
		double torque;								// ������� �������� ������
		double crankshaftSpeed;						// ������� �������� �������� ���������
		double inertMoment;							// ������ �������
		double coefH_m;								// ����������� ����������� �������� ������� �� ��������� �������
		double coefH_v;								// ����������� ����������� �������� ������� �� �������� �������� ���������
		std::vector<Linear::LineFunc> chart;		// �������� ������� ����������� ��������� ������� �� �������� �������� ���������
		std::vector<double> temperatureList;		// ����������� ����� �����������

		double HeatingRate();						// �������� �������
		double CoolingRate();						// �������� ����������
		double FindTorque(const double& x);			// �������� ����� ������ ������� � ���������� �� ��� ��������� ������� 
		void EngineOperation();						// ��������� ������ ���������

	public:
		ICE(double _overheatTemp, double _coolingCoef, double _envrmntTemp, double _inertMoment,
			std::vector<Linear::LineFunc> _chart, double _coefH_m, double _coefH_v);

		void Launch();								// ������
		void ShutDown();							// ���������
		bool IsRunning();
		double GetTorque();
		double GetCrankshaftSpeed();
		double GetInertMoment();
		double GetCoefH_m();
		double GetCoefH_v();
		std::vector<double> GetTemperatureList();
	};
}

