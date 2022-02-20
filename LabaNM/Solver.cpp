#include "Solver.h"
#include "Operations.h"
#include "Log.h"
#include <fstream>

void Solver::Dichotomy() {
	std::string col = "|xn - xn-1|";
	Log loger;
	std::ofstream log_file("Logs.txt", std::ios::app);
	std::ostream* in_cin = &std::cout;
	std::ostream* in_file = &log_file;
	auto aproximate_x = [](double a, double b) {
		return (b + a) / 2.0;
	};

	auto f = [](double x) {
		return pow(x, 3) - 4 * pow(x, 2) - 4 * x + 16;
	};
	
	double a = this->Dichotomy_range.first, b = this->Dichotomy_range.second;

	double x = aproximate_x(a, b), root = 0, previous_x = 0;

	int n = static_cast<int>(log((b - a)/this->Epsilon) / log(2)), counter = 1;

	root = f(x);
	loger.First_Log(in_cin, col);
	loger.First_Log(in_file, col);
	while (true) {
		loger.Make_Log(in_cin, counter, x, root, previous_x);
		loger.Make_Log(in_file, counter, x, root, previous_x);
		if (root == 0 || fabs(previous_x - x) <= this->Epsilon * 2.0) {
			break;
		}
		if (Operations::Sgn(f(a)) == Operations::Sgn(root)) {
			a = x;
		}
		else {
			b = x;
		}
		previous_x = x;
		x = aproximate_x(a, b);
		root = f(x);
		++counter;
	}

	loger.Last_Log(in_cin, n, counter);
	loger.Last_Log(in_file, n, counter);
	log_file.close();
	
}
void Solver::Newton() {
	std::string col = "|xn - xn-1|";
	Log loger;
	std::ofstream logfile("logs.txt", std::ios::app);
	std::ostream* in_file = &logfile;
	auto f = [](double x) {
		return pow(x, 3) - 7 * pow(x, 2) + 7 * x + 15;
	};
	auto df = [](double x) {
		return 3 * pow(x, 2) - 14 * x + 7;
	};
	auto g = [](double x, double f, double df) {
		return x - (f / df);
	};
	double x = -1.5;
	double root = f(x), previous_x = 0;
	double q = 0.92;
	int apriori = static_cast<int>((log((log(0.5 / this->Epsilon)) / (log(1.0 / q))) / log(2)) + 1) + 1;
	loger.First_Log(&std::cout, col);
	loger.First_Log(in_file, col);
	loger.Make_Log(&std::cout, 1, x, root, previous_x);
	loger.Make_Log(in_file, 1, x, root, previous_x);
	int i = 2;
	for (; fabs(previous_x - x) >= this->Epsilon * 2.0; ++i) {
		if (!df(x)) {
			break;
		}
		previous_x = x;
		x = g(x, root, df(x));
		root = f(x);
		loger.Make_Log(&std::cout, i, x, root, previous_x);
		loger.Make_Log(in_file, i, x, root, previous_x);
	}
	
	loger.Last_Log(&std::cout, apriori,  i - 1);
	loger.Last_Log(in_file, apriori, i - 1);
	logfile.close();
}
void Solver::Simple_Method() {
	std::string col = "|xn - xn-1|";
	Log loger;
	std::ofstream logfile("logs.txt", std::ios::app);
	std::ostream* in_file = &logfile;
	auto f = [](double x) {
		return pow(x, 3) - 5.0 * pow(x, 2) - 4.0 * x + 20.0;
	};
	
	auto fi = [](double x) {
		return x - 1/39.75*(pow(x, 3) - 5*pow(x, 2) - 4.0*x +20.0);
	};
	double x = this->Simple_range.second;
	double root = f(x), prev_x = 0;
	
	int i = 1;
	double q = 0.956;
	int aprior = static_cast<int>(log((fabs(fi(x) - x))/((1 - q) * this->Epsilon))/(log(1.0/q)));
	loger.First_Log(&std::cout, col);
	loger.First_Log(in_file, col);
	loger.Make_Log(&std::cout, i, x, root, prev_x);
	loger.Make_Log(in_file, i, x, root, prev_x);
	++i;
	while (fabs(x - fi(x)) > ((1.0 - q)/q ) * this->Epsilon) {
		prev_x = x;
		x = fi(x);
		root = f(x);
		loger.Make_Log(&std::cout, i, x, root, prev_x);
		loger.Make_Log(in_file, i, x, root, prev_x);
		++i;
	}
	x = fi(x);
	loger.Make_Log(&std::cout, i, x, root, prev_x);
	loger.Make_Log(in_file, i, x, root, prev_x);
	loger.Last_Log(&std::cout, aprior, i);
	loger.Last_Log(in_file, aprior, i);
}
void Solver::Set_Epsilon(const double& epsilon) {
	this->Epsilon = epsilon;
}