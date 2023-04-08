#include "test.h"

#include <FreeRTOS.h>
#include <task.h>
#include "utils.h"

void TestTask(void *notUsed)
{
  while(1)
  {
    LPRINTF("[TEST] Tick\n\r");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  vTaskDelete(NULL);
}

void TestCreate(void)
{
  LPRINTF("[TEST] Creating task\n\r");  
  BaseType_t res = xTaskCreate(TestTask,(const char *)"test",configMINIMAL_STACK_SIZE,NULL,2,NULL);
}