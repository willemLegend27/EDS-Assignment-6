#ifndef FREQUENCYCOUNTER_HPP
#define FREQUENCYCOUNTER_HPP

#include "EventGenerator.hpp"
#include "Button.hpp"
#include "Timer.hpp"

class FrequencyCounter
{
private:
    EventGenerator &eventGenerator;
    Timer &timer1;
    Button &button1;

public:
    FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1);
    void Run();

private:
    void HandleEvent(Events event);
};

#endif