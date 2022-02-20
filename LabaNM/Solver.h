#pragma once
#include <iostream>
#include <string>
#include "Log.h"
class Solver {
public:
	Solver() {};
	void Dichotomy();
	void Newton();
	void Simple_Method();
	void Set_Epsilon(const double& epsilon);
private:
	std::pair<double, double> Dichotomy_range = { -4, 1 };
	std::pair<double, double> Newton_range = { -2, 0.5 };
	std::pair<double, double> Simple_range = { -2.5, -0.5 };
	double Epsilon = 0.001;
};