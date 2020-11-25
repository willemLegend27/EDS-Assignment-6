#include "Button.hpp"
#include "Timer.hpp"
#include "stm32f3xx_hal.h"

bool triggeredEdge = false;
int nrOfVibrations = 0;

Button::Button()
{
    this->ConfigureInput();
    this->ConfigureInterrupt();
}
Button::~Button()
{
}

//interrupt PC0
extern "C" void EXTI0_IRQHandler(void)
{
    EXTI->PR |= EXTI_PR_PR0;

    Button::TriggerButton();
}

void Button::ConfigureInput()
{
    // PC0
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER0) | (0b00 << GPIO_MODER_MODER0_Pos); //input
    GPIOC->PUPDR = (GPIOC->PUPDR & ~GPIO_PUPDR_PUPDR0) | (0b01 << GPIO_PUPDR_PUPDR0_Pos); //pull-up
}
void Button::ConfigureInterrupt()
{
    //PC0
    SYSCFG->EXTICR[0] = (SYSCFG->EXTICR[0] & ~SYSCFG_EXTICR1_EXTI0_PC) | (0b010 << SYSCFG_EXTICR1_EXTI0_Pos);
    EXTI->RTSR |= EXTI_RTSR_TR0; //trigger on rising
    EXTI->FTSR |= EXTI_FTSR_TR0; //trigger on falling
    EXTI->IMR |= EXTI_IMR_MR0;
    NVIC_EnableIRQ(EXTI0_IRQn);
}

void Button::TriggerButton()
{
    nrOfVibrations += 1;
    triggeredEdge = true;
}

bool Button::IsTriggered()
{
    if (triggeredEdge == true)
    {
        triggeredEdge = false;
        return true;
    }
    else
    {
        return false;
    }
}

int Button::GetNrOfVibrations()
{
    return nrOfVibrations;
}

void Button::ResetNrOfVibrations()
{
    nrOfVibrations = 0;
}
