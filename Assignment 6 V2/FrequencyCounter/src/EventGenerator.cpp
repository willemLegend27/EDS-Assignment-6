#include "EventGenerator.hpp"
#include <iostream>

EventGenerator::EventGenerator(Button &button1, UserButton &userButton, Log &log) : button1(button1), userButton(userButton), log(log)
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
    if (userButton.ReadButton() == 0)
    {
        PushEvent(Events::UserButtonPressed);
    }
}

void EventGenerator::PushEvent(Events event)
{
    events.push_back(event);
}
