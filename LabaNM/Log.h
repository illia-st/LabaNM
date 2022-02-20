#pragma once
#include <iomanip>
class Log {
public:
	Log() {};
	void Make_Log(std::ostream* stream, int i, double x, double f_x1, double x0) {
		*stream << std::setw(3) << i << " | " << std::setw(20) << std::setprecision(10) << x << " | " << std::setw(20) << std::setprecision(10) <<
			f_x1 << " | " << std::setw(20) << std::setprecision(10) << fabs(x - x0) << std::endl;
	}
	void First_Log(std::ostream* stream, const std::string& col) {
		*stream << std::setw(3) << "i" << " | " << std::setw(20) << "x" << " | " << std::setw(20) <<
			 "f(x)" << " | " << std::setw(20) << col << std::endl;
	}

	void Last_Log(std::ostream* stream, int aprior, int n) {
		*stream << "A priori iterations = " << aprior << ", real iterations = " << n << std::endl;
		*stream << "============================================================" << std::endl;
	}
	void Error_Log(std::ostream* stream, std::string& error) {
		*stream << error << std::endl;
	}
};