#include "UserButton.hpp"
#include "stm32f3xx_hal.h"

UserButton::UserButton()
{
    this->ConfigureInput();
}
UserButton::~UserButton()
{
}

void UserButton::ConfigureInput()
{
    //PC13
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER13) | (0b00 << GPIO_MODER_MODER13_Pos); //input
    GPIOC->PUPDR = (GPIOC->PUPDR & ~GPIO_PUPDR_PUPDR13) | (0b01 << GPIO_PUPDR_PUPDR13_Pos); //pullup
}

int UserButton::ReadButton()
{
    return GPIOC->IDR & GPIO_IDR_13;
}
