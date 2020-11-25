#ifndef FREQUENCYCOUNTER_HPP
#define FREQUENCYCOUNTER_HPP

#include "EventGenerator.hpp"
#include "Button.hpp"
#include "Timer.hpp"
#include "Log.hpp"
#include "States.hpp"

class FrequencyCounter
{
private:
    EventGenerator &eventGenerator;
    Timer &timer1;
    Button &button1;
    Log &log;
    States currentState;

public:
    FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1, Log &log);
    void Run();

private:
    void HandleEvent(Events event);
    void HandleMeasureFrequency(Events event);
    void HandleMeasurePeriod(Events event);
    double MeaureFrequency();
    void PrintFrequencyOutput(double frequency);
    double MeaurePeriod();
    void PrintPeriodOutput(double period);
    void ResetState();
    void OutputState();
};

#endif