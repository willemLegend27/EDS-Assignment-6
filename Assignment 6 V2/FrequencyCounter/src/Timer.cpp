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
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    TIM1->PSC = 1 << 1;    //1 MHz
    TIM1->ARR = 36000 - 1; // interrupt count
    TIM1->CR1 |= TIM_CR1_CEN;
}

void Timer::Tick()
{
    timer1Ticks += 1;
}

void Timer::EnableTimer()
{
    NVIC_EnableIRQ(TIM1_CC_IRQn);
    TIM1->DIER |= TIM_DIER_CC1IE;
}

void Timer::DisableTimer()
{
    NVIC_DisableIRQ(TIM1_CC_IRQn);
    TIM1->DIER &= ~TIM_DIER_CC1IE;
}
