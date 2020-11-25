#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
private:
public:
    Button();
    ~Button();
    static void TriggerButton();
    bool IsTriggered();
    int GetNrOfVibrations();
    void ResetNrOfVibrations();

private:
    void ConfigureInput();
    void ConfigureInterrupt();
};

#endif