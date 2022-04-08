#include "Test.h"

namespace EngineTest {
	Test::Test() {

	}

	void Test::MonitoringTemp(ICE& engine) {
		while (engine.GetTemperature() < engine.GetOverheatTemp() && engine.IsRunning()) {		// наблюдаем за температурой, пока она не критическая
			std::this_thread::sleep_for(std::chrono::milliseconds(25));							// или движок не выключится сам из-за таймаута
		}
		engine.ShutDown();																		// после пергрева отключаем
		return;
	}

	 double Test::TestICE(ICE& engine) {
		std::thread monitoring(&Test::MonitoringTemp, this, std::ref(engine));	// запуск в поток процедуры слежки за температурой
		monitoring.detach();
		engine.Launch();														// запуск двигателя				
		return static_cast<int>(engine.GetTemperatureList().size());						// возвращает время (время = размеру отчета)
	}
}