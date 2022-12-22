#include "ConsoleInterface.h"
#include "simulator.h"
#include "EngineParameters.h"

int main()
{
    double ambient_temperature = InputAmbientTemperature();
    simulator test(ambient_temperature);
    int time = test.StartTest();
    if (time == MAX_TIME)
    {
        OutputErr();
        return -1;
    }

    OutputOverheatingTime(time);
    return 0;
}

