#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>

namespace EngineTest {
	class Test
	{
	private:
		void MonitoringTemp(ICE& engine);	// ���������� ����������� ���
	public:
		Test();
		double TestICE(ICE& engine); // ������ ����� ���
	};
}

