#include "test.h"

#include <assert.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <stdbool.h>
#include <stdint.h>
#include <task.h>
#include "utils.h"

#define TIME_OUT_MS 10000
#define QUEUE_LENGTH 5
QueueHandle_t queue;

void ProducerTask(void *notUsed)
{
  uint32_t data = 0;
  while(1)
  {
    LPRINTF("[PRODUCER] Enqueue\n\r");
    bool dataEnqueue = (pdPASS == xQueueSend(queue, &data, pdMS_TO_TICKS(TIME_OUT_MS)));
    if (dataEnqueue)
    {
      ++data;
    }
    else
    {
      LPRINTF("[PRODUCER] Timeout, could not enqueue\n\r");
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  vTaskDelete(NULL);
}

void ConsumerTask(void *notUsed)
{
  uint32_t data = 0;
  while(1)
  {
    bool dataDequeue = (pdPASS == xQueueReceive(queue, &data, pdMS_TO_TICKS(TIME_OUT_MS)));
    if (dataDequeue)
    {
      LPRINTF("[CONSUMER] Dequeue %d\n\r", data);
    }
    else
    {
      LPRINTF("[CONSUMER] Timeout, could not dequeue\n\r");
    }
  }
  vTaskDelete(NULL);
}

void TestCreate(void)
{
  BaseType_t res;
  LPRINTF("[TEST] Creating queue\n\r");
  queue = xQueueCreate(QUEUE_LENGTH, sizeof(uint32_t));
  if(NULL == queue)
  {
    LPRINTF("[TEST] Could not create queue\n\r");
    assert(queue);
  }

  LPRINTF("[TEST] Creating producer\n\r");
  res = xTaskCreate(ProducerTask,(const char *)"Producer",configMINIMAL_STACK_SIZE,NULL,2,NULL);
  configASSERT(pdPASS == res);

  LPRINTF("[TEST] Creating consumer\n\r");
  res = xTaskCreate(ConsumerTask,(const char *)"Consumer",configMINIMAL_STACK_SIZE,NULL,2,NULL);
  configASSERT(pdPASS == res);

  LPRINTF("[TEST] Creation complete");
}