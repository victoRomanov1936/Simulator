#pragma once
#include "EngineParameters.h"

class simulator
{
private:
	int index;
	double ambient_temperature;
	double engine_temperature;
	Engines test_engine;
public:
	int StartTest();
	simulator(double ambient_temperature);
};

