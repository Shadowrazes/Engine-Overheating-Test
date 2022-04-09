#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>

namespace EngineTest {
	class TestArea
	{
	private:
		void MonitoringTemp(Engine* engine, double& time);	// мониторинг температуры ДВС
	public:
		TestArea();
		double Launch(Engine* engine);	// запуск теста, приводит передаваемый тип двигателя к базовому классу
	};
}

