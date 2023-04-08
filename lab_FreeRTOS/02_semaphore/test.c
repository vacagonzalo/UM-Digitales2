#include "test.h"

#include <assert.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <stdbool.h>
#include <stdint.h>
#include <task.h>
#include "utils.h"

#define TIME_OUT_MS 10000
SemaphoreHandle_t semaphore;

void PrinterTask(void *param)
{
  uint32_t taskId = (uint32_t)param;
  while(1)
  {
    bool semaphoreTaken = (pdFALSE == xSemaphoreTake(semaphore,pdMS_TO_TICKS(TIME_OUT_MS)));
    if (semaphoreTaken)
    {
      LPRINTF("[PRINTER] id: %d\n\r", taskId);
      xSemaphoreGive(semaphore);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  vTaskDelete(NULL);
}


void TestCreate(void)
{
  BaseType_t res;
  LPRINTF("[TEST] Creating queue\n\r");
  semaphore = xSemaphoreCreateBinary();
  if(NULL == semaphore)
  {
    LPRINTF("[TEST] Could not create semaphore\n\r");
    assert(semaphore);
  }

  for(uint32_t i = 0; i < 5; ++i)
  {
    LPRINTF("[TEST] Printer %d\n\r", i);
    res = xTaskCreate(PrinterTask,(const char *)"Print",configMINIMAL_STACK_SIZE,(void *)i,2,NULL);
    configASSERT(pdPASS == res);
  }

  LPRINTF("[TEST] Creation complete\n\r");
}