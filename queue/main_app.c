#include <FreeRTOS.h>
#include <task.h>
#include "console.h"
#include "test.h"

void main_app(void)
{
  console_print("main app starting\n\r");
  TestCreate();
  vTaskStartScheduler();
  for(;;)
  {
  }
}