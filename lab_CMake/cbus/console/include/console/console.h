#ifndef CONSOLE_CONSOLE_H
#define CONSOLE_CONSOLE_H

#include <stdint.h>

void Console_init();

void Console_send(uint32_t *data, uint32_t size);

#endif // CONSOLE_CONSOLE_H
