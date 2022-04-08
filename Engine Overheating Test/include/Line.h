#pragma once

namespace Linear {

	struct Point {
		double X = 0;
		double Y = 0;
	};

	class Line {
	protected:
		Point start;	// ������ �������
		Point end;		// ����� �������

	public:
		Line(Point _start, Point _end);

		virtual Point GetStart();
		virtual Point GetEnd();
	};
}

