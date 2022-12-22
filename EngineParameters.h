#pragma once
#include <vector>
#define ERROR_VALUE 10e-2
#define MAX_TIME 1000

struct Engines 
{
	double Vc(double ambient_temperature, double engine_temperature);
	double Vh();

	std::vector<double> M { 20, 75, 100, 105, 75, 0 };
	std::vector<double> V { 0, 75, 150, 200, 250, 300 };

	double I = 0.1;
	double startM;
	double startV;
	double overheat_temp = 110;
	double Hm = 0.01;
	double Hv = 0.0001;
	double C = 0.1;
};
