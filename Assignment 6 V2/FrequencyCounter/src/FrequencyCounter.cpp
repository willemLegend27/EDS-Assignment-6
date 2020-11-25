#include "FrequencyCounter.hpp"

#include <string>

FrequencyCounter::FrequencyCounter(EventGenerator &eventGenerator, Timer &timer1, Button &button1, Log &log) : eventGenerator(eventGenerator), timer1(timer1), button1(button1), log(log)
{
    currentState = MEASURE_PERIOD;
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
    case STANDBY:
        if (event == UserButtonPressed)
        {
            currentState = MEASURE_PERIOD;
            OutputState();
        }
    case MEASURE_PERIOD:
        HandleMeasurePeriod(event);
        if (event == UserButtonPressed)
        {
            currentState = MEASURE_FREQUENCY;
            OutputState();
        }
        break;
    case MEASURE_FREQUENCY:
        HandleMeasureFrequency(event);
        if (event == UserButtonPressed)
        {
            currentState = STANDBY;
            OutputState();
        }
        break;
    default:
        return;
    }
}

void FrequencyCounter::OutputState()
{
    std::string msg = "Current State : " + std::to_string(currentState) + "\r\n";
    log.Trace(msg.c_str());
}

void FrequencyCounter::HandleMeasureFrequency(Events event)
{
    if (event == ButtonTriggered)
    {
        if (timer1.GetTimerTicks() == 0)
        {
            timer1.EnableTimer();
        }
        else if (timer1.GetTimerTicks() > 0)
        {
            double frequency = MeaureFrequency();
            PrintFrequencyOutput(frequency);
            ResetState();
        }
    }
}

void FrequencyCounter::HandleMeasurePeriod(Events event)
{
    if (event == ButtonTriggered)
    {
        if (timer1.GetTimerTicks() == 0)
        {
            timer1.EnableTimer();
        }
        else if (timer1.GetTimerTicks() > 0)
        {
            double period = MeaurePeriod();
            PrintPeriodOutput(period);
            ResetState();
        }
    }
}

void FrequencyCounter::ResetState()
{
    timer1.DisableTimer();
    timer1.ResetTimerTicks();
    button1.ResetNrOfVibrations();
    currentState = STANDBY;
    OutputState();
}

void FrequencyCounter::PrintPeriodOutput(double period)
{
    std::string msg = "Period of signal : " + std::to_string(period) + " ms\r\n";
    log.Trace(msg.c_str());
}

double FrequencyCounter::MeaurePeriod()
{
    return timer1.GetTimerTicks();
}

void FrequencyCounter::PrintFrequencyOutput(double frequency)
{
    std::string msg = "Frequency of signal : " + std::to_string(frequency) + " Hz\r\n";
    log.Trace(msg.c_str());
}

double FrequencyCounter::MeaureFrequency()
{
    return timer1.GetTimerTicks() / button1.GetNrOfVibrations();
}
