#ifndef _UTILS_H
#define _UTILS_H

#include "console.h"
#define LPRINTF(fmt, ...) console_print(fmt, ##__VA_ARGS__)

#endif // _UTILS_H