#ifndef EVENTGENERATOR_HPP
#define EVENTGENERATOR_HPP

#include "Events.hpp"
#include "Button.hpp"
#include <vector>

class EventGenerator
{
private:
    Button &button1;
    std::vector<Events> events;

public:
    EventGenerator(Button &button1);
    EventGenerator(const EventGenerator &other) = delete;
    EventGenerator &operator=(const EventGenerator &) = delete;
    Events GetEvent();

private:
    void HandlePollEvents();
    void PushEvent(Events event);
};

#endif
