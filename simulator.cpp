#include "simulator.h"

int simulator::StartTest()
{
    double a = test_engine.startM * test_engine.startV;
    double eps = test_engine.overheat_temp - engine_temperature;
    int working_time = 0;

    while (eps > ERROR_VALUE && working_time < MAX_TIME)
    {
        working_time += 1;
        test_engine.startV += a;

        if (index < test_engine.M.size()-2) {
            index += test_engine.startV < test_engine.V[index + 1] ? 0 : 1;
        }

        double up = test_engine.startV - test_engine.V[index];
        double down = test_engine.V[index + 1] - test_engine.V[index];
        double factor = test_engine.M[index + 1] - test_engine.M[index];

        test_engine.startM = up / down * factor + test_engine.M[index];

        engine_temperature += test_engine.Vc(ambient_temperature, engine_temperature) + test_engine.Vh();

        a = test_engine.startM * test_engine.I;
        eps = test_engine.overheat_temp - engine_temperature;
    }

    return working_time;
}

simulator::simulator(double ambient_temperature)
{
    index = 0;
    test_engine.startM = test_engine.M[index];
    test_engine.startV = test_engine.V[index];
    engine_temperature = ambient_temperature;
    this->ambient_temperature = ambient_temperature;
}
