#include "ConsoleInterface.h"
#include <iostream>

double InputAmbientTemperature()
{
	double ambient_temperature;
	std::cout << "Enter ambient temperature: ";
	std::cin >> ambient_temperature;
	return ambient_temperature;
}
void OutputErr()
{
	std::cout << "does not overheat\n";
}
void OutputOverheatingTime(int time)
{
	std::cout << "Time of overheating: "<<time<<"\n";
}
