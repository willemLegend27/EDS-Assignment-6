#ifndef FREQUENCYCOUNTER_HPP
#define FREQUENCYCOUNTER_HPP

#include "EventGenerator.hpp"
#include "Button.hpp"
#include "Timer.hpp"
#include "States.hpp"

class FrequencyCounter
{
private:
    EventGenerator &eventGenerator;
    Timer &timer1;
    Button &button1;
    States currentState;

public:
    FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1);
    void Run();

private:
    void HandleEvent(Events event);
    void HandleMeasureFrequency(Events event);
    void HandleMeasurePeriod(Events event);
};

#endif