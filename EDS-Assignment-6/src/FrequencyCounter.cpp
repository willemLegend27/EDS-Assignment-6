#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1) : eventGenerator(eventGenerator), timer1(timer1), button1(button1)
{
}

void FrequencyCounter::Run()
{
    Events event = eventGenerator.GetEvent();
    HandleEvent(event);
}

void HandleEvent(Events event)
{
}