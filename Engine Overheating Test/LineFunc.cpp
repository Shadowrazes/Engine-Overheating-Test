#include "LineFunc.h"

namespace Linear {

	LineFunc::LineFunc(Point _start, Point _end) : Line(_start, _end) {

	}

	double LineFunc::Func(const double& x) {
		return (x - start.X) * (end.Y - start.Y) / (end.X - start.X) + start.Y;
	}
}