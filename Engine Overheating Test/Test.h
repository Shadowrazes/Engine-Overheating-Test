#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>
#include <iostream>

namespace EngineTest {
	class Test
	{
	private:
		void MonitoringTemp(ICE& engine);	// мониторинг температуры ДВС
	public:
		Test();
		double TestICE(ICE& engine); // запуск теста ДВС
	};
}

