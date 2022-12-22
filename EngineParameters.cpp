#include "EngineParameters.h"

double Engines::Vc(double ambient_temperature, double engine_temperature)
{
	return C * (ambient_temperature - engine_temperature);
}

double Engines::Vh()
{
	return startM * Hm + startV * startV * Hv;
}
