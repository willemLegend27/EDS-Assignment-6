#ifndef LOG_HPP
#define LOG_HPP

#include "main.h"
#include "stm32f3xx_hal.h"

class Log
{
private:
    UART_HandleTypeDef &huart2;

public:
    Log(UART_HandleTypeDef &huart);
    virtual void Trace(const char *fmt);

private:
    void Write(const char *fmt);
};

#endif