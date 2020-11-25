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
    int GetTimerTicks();
    void ResetTimerTicks();

private:
    void ConfigureInterrupt();
};

#endif