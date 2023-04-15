#include "console/console.h"

#include <stdio.h>

void Console_init()
{
    // FIXME: do something?
}

void Console_send(uint32_t *data, uint32_t size)
{
    printf("==========\n\r");
    for (uint32_t i = 0; i < size; ++i)
    {
        printf("0x%08x\n\r", data[i]);
    }
    printf("==========\n\n\r");
}
