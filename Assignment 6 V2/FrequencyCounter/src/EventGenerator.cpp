#include "EventGenerator.hpp"
#include <iostream>

EventGenerator::EventGenerator(Button &button1) : button1(button1)
{
}

Events EventGenerator::GetEvent()
{
    Events result = NoEventOccured;

    HandlePollEvents();

    if (events.size() > 0)
    {
        result = events[0];
        events.erase(events.begin());
    }

    return result;
}

void EventGenerator::HandlePollEvents()
{
    if (button1.IsTriggered())
    {
        PushEvent(Events::ButtonTriggered);
    }
}

void EventGenerator::PushEvent(Events event)
{
    events.push_back(event);
}
