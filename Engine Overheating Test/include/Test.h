#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>

namespace EngineTest {
	class Test
	{
	private:
		void MonitoringTemp(ICE& engine, double& time);	// мониторинг температуры ДВС
	public:
		Test();
		double TestICE(ICE& engine);	// запуск теста ДВС
	};
}

