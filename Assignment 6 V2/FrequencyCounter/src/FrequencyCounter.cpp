#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1) : eventGenerator(eventGenerator), timer1(timer1), button1(button1)
{
    currentState = MEASURE_FREQUENCY;
}

void FrequencyCounter::Run()
{
    Events event = eventGenerator.GetEvent();
    HandleEvent(event);
}

void FrequencyCounter::HandleEvent(Events event)
{
    switch (currentState)
    {
    case MEASURE_FREQUENCY:
        HandleMeasureFrequency(event);
        break;
    case MEASURE_PERIOD:
        HandleMeasurePeriod(event);
        break;
    default:
        return;
    }
}

void FrequencyCounter::HandleMeasureFrequency(Events event)
{
    if (button1.ReadButton() == 0)
    {
        if (event == ButtonTriggered)
        {
            timer1.EnableTimer();
        }
    }
}

void FrequencyCounter::HandleMeasurePeriod(Events event)
{
}