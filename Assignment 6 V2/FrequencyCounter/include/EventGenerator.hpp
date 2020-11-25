#ifndef EVENTGENERATOR_HPP
#define EVENTGENERATOR_HPP

#include "Events.hpp"
#include "Button.hpp"
#include "UserButton.hpp"
#include "Log.hpp"
#include <vector>

class EventGenerator
{
private:
    Button &button1;
    UserButton &userButton;
    Log &log;
    std::vector<Events> events;

public:
    EventGenerator(Button &button1, UserButton &userbutton, Log &log);
    Events GetEvent();

private:
    void HandlePollEvents();
    void PushEvent(Events event);
};

#endif
