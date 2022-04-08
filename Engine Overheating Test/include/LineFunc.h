#pragma once

#include "Line.h"

namespace Linear {

	class LineFunc : public Line
	{

	public:
		LineFunc(Point _start, Point _end);

		double Func(const double& x);			// функция на отрезке
	};
}