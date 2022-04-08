#include "include/Test.h"

namespace EngineTest {
	Test::Test() {

	}

	void Test::MonitoringTemp(ICE& engine) {
		int timeout = 198;
		double time = 0;
		while (engine.GetTemperature() < engine.GetOverheatTemp() 
			&& timeout > time) {															// наблюдаем за температурой, пока она не критическая
			std::this_thread::sleep_for(std::chrono::milliseconds(25));						// или пока не истечет время теста
			time += 0.5;
		}
		engine.ShutDown();																	// после пергрева отключаем
		return;
	}

	 double Test::TestICE(ICE& engine) {
		std::thread monitoring(&Test::MonitoringTemp, this, std::ref(engine));	// запуск в поток процедуры слежки за температурой
		monitoring.detach();
		engine.Launch();														// запуск двигателя				
		return static_cast<double>(engine.GetTemperatureList().size());						// возвращает время (время = размеру отчета)
	}
}