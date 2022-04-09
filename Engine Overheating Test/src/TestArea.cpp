#include "../include/TestArea.h"

namespace EngineTest {
	TestArea::TestArea() {

	}

	void TestArea::MonitoringTemp(Engine* engine, double& time) {
		int timeout = 200;
		while (engine->GetTemperature() < engine->GetOverheatTemp()
			&& timeout > time) {											// наблюдаем за температурой, пока она не критическая
			std::this_thread::sleep_for(std::chrono::milliseconds(25));			// или пока не истечет время теста
			time += 0.5;
		}
		engine->ShutDown();														// после пергрева отключаем
		return;
	}

	 double TestArea::Launch(Engine* engine) {
		double time = 0;
		std::thread monitoring(&TestArea::MonitoringTemp, this, std::ref(engine), std::ref(time)); // запуск в поток процедуры слежки за температурой
		monitoring.detach();
		engine->Launch();														// запуск двигателя				
		return time;															// возвращает время нагрева
	}
}