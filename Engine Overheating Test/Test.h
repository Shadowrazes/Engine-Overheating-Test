#pragma once
#include "ICE.h"
#include <thread>
#include <chrono>
#include <iostream>

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

