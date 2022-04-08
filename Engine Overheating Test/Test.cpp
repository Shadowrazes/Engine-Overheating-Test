#include "Test.h"

namespace EngineTest {
	Test::Test() {

	}

	void Test::MonitoringTemp(ICE& engine) {
		while (engine.GetTemperature() < engine.GetOverheatTemp() && engine.IsRunning()) {		// ��������� �� ������������, ���� ��� �� �����������
			std::this_thread::sleep_for(std::chrono::milliseconds(25));							// ��� ������ �� ���������� ��� ��-�� ��������
		}
		engine.ShutDown();																		// ����� �������� ���������
		return;
	}

	 double Test::TestICE(ICE& engine) {
		std::thread monitoring(&Test::MonitoringTemp, this, std::ref(engine));	// ������ � ����� ��������� ������ �� ������������
		monitoring.detach();
		engine.Launch();														// ������ ���������				
		return static_cast<int>(engine.GetTemperatureList().size());						// ���������� ����� (����� = ������� ������)
	}
}