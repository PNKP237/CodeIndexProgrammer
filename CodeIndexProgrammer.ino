#include "driver/twai.h"
#define DEBUG
//#define DISABLE_PROGRAMMING

#ifdef DEBUG
#define DEBUG_SERIAL(X) Serial.begin(X)
#define DEBUG_PRINT(X) Serial.print(X)
#define DEBUG_PRINTLN(X) Serial.println(X)
#define DEBUG_PRINTF(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_SERIAL(X)
#define DEBUG_PRINT(X)
#define DEBUG_PRINTLN(X)
#define DEBUG_PRINTF(...)
#endif
// defining available flags in the eventGroup

#define CAN_ehuStarted (1 << 6)
#define CAN_startProgramming (1 << 0)
#define CAN_startDumping (1 << 5)
#define CAN_dumpingFinished (1 << 7)
#define CAN_waitingForISO (1 << 1)
#define CAN_receivedCodeIndex (1 << 2)
#define CAN_requestedCodeIndexProgramming (1 << 11)
#define CAN_sentFirstProgrammingFrame (1 << 10)
#define CAN_receivedProgrammingAllow (1 << 3)
#define CAN_ehuDumpStarted (1 << 4)
#define CAN_MessageReady (1 << 8)
#define CAN_softwareVersionOkay (1 << 9)
#define CAN_softwareVersionWrong (1 << 12)
#define CAN_softwareVersionRequested (1<<13)
#define CAN_softwareVersionReceived (1<<14)
#define CAN_programmingFinished (1<<15)

// RTOS stuff
TaskHandle_t canReceiveTaskHandle, canDisplayTaskHandle, canProcessTaskHandle, canTransmitTaskHandle, indexProgrammerTaskHandle;
QueueHandle_t canRxQueue, canTxQueue;
EventGroupHandle_t eventGroup;

void setup() {
  DEBUG_SERIAL(921600);
  canRxQueue=xQueueCreate(100, sizeof(twai_message_t));
  canTxQueue=xQueueCreate(100, sizeof(twai_message_t));
  eventGroup=xEventGroupCreate();
  xTaskCreatePinnedToCore(canReceiveTask, "CANbusReceiveTask", 4096, NULL, 1, &canReceiveTaskHandle, 1);
  xTaskCreatePinnedToCore(canTransmitTask, "CANbusTransmitTask", 4096, NULL, 1, &canTransmitTaskHandle, 0);
  xTaskCreatePinnedToCore(canProcessTask, "CANbusMessageProcessor", 8192, NULL, 2, &canProcessTaskHandle, 0);
  xTaskCreatePinnedToCore(indexProgrammerTask, "CANbusindexProgrammerTask", 8192, NULL, 3, &indexProgrammerTaskHandle, 0);
  twai_init();
  vTaskDelay(pdMS_TO_TICKS(3000));
  DEBUG_PRINTF("\r\nStarted! Press 7 for about 2 seconds to check the software version, afterwards you can follow the instructions to dump the Code Index.\r\n");
  ehu_force_testmode();
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(1000));
  if(checkFlag(CAN_softwareVersionWrong)){
    DEBUG_PRINTF("Wrong software version! Aborting.\r\n");
  }
}
