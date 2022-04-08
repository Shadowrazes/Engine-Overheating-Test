#include "include/Test.h"

namespace EngineTest {
	Test::Test() {

	}

	void Test::MonitoringTemp(ICE& engine) {
		int timeout = 198;
		double time = 0;
		while (engine.GetTemperature() < engine.GetOverheatTemp() 
			&& timeout > time) {															// ��������� �� ������������, ���� ��� �� �����������
			std::this_thread::sleep_for(std::chrono::milliseconds(25));						// ��� ���� �� ������� ����� �����
			time += 0.5;
		}
		engine.ShutDown();																	// ����� �������� ���������
		return;
	}

	 double Test::TestICE(ICE& engine) {
		std::thread monitoring(&Test::MonitoringTemp, this, std::ref(engine));	// ������ � ����� ��������� ������ �� ������������
		monitoring.detach();
		engine.Launch();														// ������ ���������				
		return static_cast<double>(engine.GetTemperatureList().size());						// ���������� ����� (����� = ������� ������)
	}
}