#include "Log.hpp"

#include <string.h>

Log::Log(UART_HandleTypeDef &huart) : huart2(huart) {}

void Log::Trace(const char *fmt)
{
    Write(fmt);
}

void Log::Write(const char *fmt)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)fmt, strlen(fmt), HAL_MAX_DELAY);
}
