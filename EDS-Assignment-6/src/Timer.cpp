#include "Timer.hpp"
#include "stm32f3xx_hal.h"
#include <stdexcept>

static long int timer1Ticks;

Timer::Timer()
{
    this->ConfigureInterrupt();
}
Timer::~Timer()
{
}

extern "C" void TIM1_CC_IRQHandler()
{
    TIM1->SR &= ~TIM_SR_CC1IF;
    Timer::Tick();
}

void Timer::ConfigureInterrupt()
{

    int delayInS = 1;

    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    TIM1->PSC = (delayInS << 1) - 1;
    TIM1->ARR = 36000 - 1;
    TIM1->DIER |= TIM_DIER_CC1IE;
    NVIC_EnableIRQ(TIM1_CC_IRQn);
    TIM1->CR1 |= TIM_CR1_CEN;
}

void Timer::Tick()
{
    timer1Ticks += 1;
}
