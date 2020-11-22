#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
private:
public:
    Button();
    ~Button();
    static void TriggerButton();
    static int ReadButton();
    bool IsTriggered();

private:
    void ConfigureInput();
    void ConfigureInterrupt();
};

#endif