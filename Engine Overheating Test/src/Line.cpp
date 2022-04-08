#include "include/Line.h"

namespace Linear {

	Line::Line(Point _start, Point _end) : start(_start), end(_end) {

	}

	Point Line::GetStart() {
		return start;
	}

	Point Line::GetEnd() {
		return end;
	}
}