#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>

namespace EngineTest {
	class Test
	{
	private:
		void MonitoringTemp(Engine* engine, double& time);	// мониторинг температуры ДВС
	public:
		Test();
		double Launch(Engine* engine);	// запуск теста, приводит передаваемый тип двигателя к базовому классу
	};
}

