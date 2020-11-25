#ifndef USERBUTTON_HPP
#define USERBUTTON_HPP

class UserButton
{
private:
public:
    UserButton();
    ~UserButton();
    int ReadButton();

private:
    void ConfigureInput();
};

#endif