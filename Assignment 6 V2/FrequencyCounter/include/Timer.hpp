#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
private:
    

public:
    Timer();
    ~Timer();
    static void Tick();
    void EnableTimer();
    void DisableTimer();

private:
    void ConfigureInterrupt();
};

#endif