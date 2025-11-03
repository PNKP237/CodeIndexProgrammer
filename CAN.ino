const twai_message_t
  ehu_bong_start={ .identifier=0x201, .data_length_code=3, .data={0x01, 0xFF, 0x00}},
  ehu_bong_end={ .identifier=0x201, .data_length_code=3, .data={0x01, 0xFF, 0x32}},
  opcom_helloEHU={ .identifier=0x241, .data_length_code=8, .data={0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, // expect 641 # 01 60 ...
  opcom_resetEHU={ .identifier=0x241, .data_length_code=8, .data={0x03, 0x3B, 0x5E, 0x01, 0x55, 0x55, 0x55, 0x55}}, // expect 641 # 03 7F 3B 78 ... and 641 # 02 7B 5E afterwards
  opcom_requestPartID={ .identifier=0x241, .data_length_code=8, .data={0x02, 0x1A, 0x9A, 0x55, 0x55, 0x55, 0x55, 0x55}},
  opcom_requestCodeIndex={ .identifier=0x241, .data_length_code=8, .data={0x02, 0x1A, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00}},
  opcom_requestSwVer={ .identifier=0x241, .data_length_code=8, .data={0x02, 0x1A, 0x7B, 0x55, 0x55, 0x55, 0x55, 0x55}},
  ISO_AcceptTransmission={ .identifier=0x241, .data_length_code=8, .data={0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
  opcom_requestCodeIndexDump={ .identifier=0x241, .data_length_code=8, .data={0x06, 0x23, 0x00, 0x00, 0x00, 0x00, 0xAB, 0x00}};


const twai_message_t
  codeIndex01201[26]={    // entire struct of the 01201 code index
    { .identifier=0x241, .data_length_code=8, .data={0x10, 0xB0, 0x3B, 0x3E, 0x00, 0x00, 0xAB, 0x30}},
    { .identifier=0x241, .data_length_code=8, .data={0x21, 0x31, 0x32, 0x30, 0x31, 0x00, 0x00, 0x02}},
    { .identifier=0x241, .data_length_code=8, .data={0x22, 0x05, 0x0A, 0x00, 0x00, 0xDE, 0x03, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x23, 0xE4, 0x00, 0x04, 0x00, 0x00, 0x0E, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x24, 0x00, 0xE9, 0x00, 0x00, 0x00, 0xE8, 0x28}},
    { .identifier=0x241, .data_length_code=8, .data={0x25, 0x00, 0x01, 0x64, 0xC8, 0xFF, 0x01, 0x64}},
    { .identifier=0x241, .data_length_code=8, .data={0x26, 0xC8, 0xFF, 0xB3, 0x00, 0x00, 0x00, 0x32}},
    { .identifier=0x241, .data_length_code=8, .data={0x27, 0x48, 0x48, 0x4C, 0x1E, 0x46, 0xB4, 0x50}},
    { .identifier=0x241, .data_length_code=8, .data={0x28, 0x96, 0x02, 0x32, 0x48, 0x00, 0x28, 0x4C}},
    { .identifier=0x241, .data_length_code=8, .data={0x29, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x2A, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x05}},
    { .identifier=0x241, .data_length_code=8, .data={0x2B, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x2C, 0x00, 0x00, 0x00, 0x15, 0x23, 0x03, 0x01}},
    { .identifier=0x241, .data_length_code=8, .data={0x2D, 0x00, 0x11, 0x1F, 0x03, 0x00, 0x00, 0x27}},
    { .identifier=0x241, .data_length_code=8, .data={0x2E, 0x00, 0x00, 0x00, 0x21, 0x09, 0x03, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x2F, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x20, 0x00, 0x0E, 0x00, 0x02, 0x00, 0x0E, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x21, 0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    { .identifier=0x241, .data_length_code=8, .data={0x29, 0x00, 0x5A, 0x00, 0x00, 0xAE, 0x00, 0x00}}
  };

// below functions are used to simplify interaction with freeRTOS eventGroups
void setFlag(uint32_t bit){
  xEventGroupSetBits(eventGroup, bit);
}

// clears an event bit
void clearFlag(uint32_t bit){
  xEventGroupClearBits(eventGroup, bit);
}

// waits for an event bit to be set, blocking indefinitely if 2nd argument not provided
void waitForFlag(uint32_t bit, TickType_t ticksToWait=portMAX_DELAY){
  xEventGroupWaitBits(eventGroup, bit, pdFALSE, pdTRUE, ticksToWait);
}

// Check if a specific event bit is set (without blocking)
bool checkFlag(uint32_t bit){
  EventBits_t bits=xEventGroupGetBits(eventGroup);
  return (bits&bit)!=0;
}
// initializing CAN communication
void twai_init(){
  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_5, GPIO_NUM_4, TWAI_MODE_NORMAL);         // CAN bus set up
  g_config.rx_queue_len=40;
  g_config.tx_queue_len=5;
  g_config.intr_flags=(ESP_INTR_FLAG_NMI & ESP_INTR_FLAG_IRAM);   // run the TWAI driver at the highest possible priority
  twai_timing_config_t t_config =  {.brp = 42, .tseg_1 = 15, .tseg_2 = 4, .sjw = 3, .triple_sampling = false};    // set CAN prescalers and time quanta for 95kbit
  twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();
    DEBUG_PRINT("\nCAN/TWAI SETUP => "); 
  if(twai_driver_install(&g_config, &t_config, &f_config) == ESP_OK) {
      DEBUG_PRINT("DRV_INSTALL: OK ");
  } else {
      DEBUG_PRINT("DRV_INST: FAIL ");
  }
  if (twai_start() == ESP_OK) {
      DEBUG_PRINT("DRV_START: OK ");
  } else {
      DEBUG_PRINT("DRV_START: FAIL ");
  }
  uint32_t alerts_to_enable=TWAI_ALERT_TX_SUCCESS;
  if(twai_reconfigure_alerts(alerts_to_enable, NULL) == ESP_OK){
      DEBUG_PRINTLN("ALERTS: OK \n");
  } else {
      DEBUG_PRINTLN("ALERTS: FAIL \n");
  }
}

// this task only reads CAN messages, filters them and enqueues them to be decoded ansynchronously
void canReceiveTask(void *pvParameters){
  twai_message_t Recvd_CAN_MSG;
  while(1){
    if(twai_receive(&Recvd_CAN_MSG, portMAX_DELAY)==ESP_OK){
      switch(Recvd_CAN_MSG.identifier){
        case 0x201:
        case 0x641:
          xQueueSend(canRxQueue, &Recvd_CAN_MSG, portMAX_DELAY);      // queue the message contents to be read at a later time
          break;
        default: break;
      }
    }
  }
}

// this task processes filtered CAN frames read from canRxQueue
void canProcessTask(void *pvParameters){
  static twai_message_t RxMsg;
  uint8_t sw_year=0, sw_month[2]={0}, sw_day[2]={0};
  while(1){
    xQueueReceive(canRxQueue, &RxMsg, portMAX_DELAY);     // receives data from the internal queue
    switch(RxMsg.identifier){
      case 0x201: {
        switch(RxMsg.data[1]){
          case 0x37:{
            if(!checkFlag(CAN_softwareVersionOkay) && RxMsg.data[2]==20){
              xQueueSend(canTxQueue, &opcom_requestSwVer, portMAX_DELAY);
              setFlag(CAN_softwareVersionRequested);
              DEBUG_PRINTF("Checking the software version...\r\n");
            } else {
              if(checkFlag(CAN_softwareVersionOkay) && RxMsg.data[2]==20){
                setFlag(CAN_startDumping);
                xQueueSend(canTxQueue, &opcom_requestCodeIndexDump, portMAX_DELAY);
              }
            }
            break;
          }
          case 0x39:{
            if(RxMsg.data[2]==0x0A && checkFlag(CAN_dumpingFinished) && checkFlag(CAN_softwareVersionOkay)) setFlag(CAN_startProgramming);
            break;
          }
          default: break;
        }
        break;
      }
      case 0x641:{    // this will dump all the received data from 0x641
        if(checkFlag(CAN_waitingForISO) && RxMsg.data[0]==0x10){  // this is a mess, yes. but it does work - if it ain't broken, don't fix it.
          xQueueSend(canTxQueue, &ISO_AcceptTransmission, portMAX_DELAY);
          clearFlag(CAN_waitingForISO);
        }
        if(checkFlag(CAN_softwareVersionOkay) && !checkFlag(CAN_softwareVersionWrong) && checkFlag(CAN_softwareVersionReceived) && !checkFlag(CAN_programmingFinished)){
          if(checkFlag(CAN_startDumping) && !checkFlag(CAN_startProgramming) && !checkFlag(CAN_dumpingFinished) && RxMsg.data[0]!=0x30){
            if(RxMsg.data[0]==0x10) DEBUG_PRINTF("Starting index code dump, make sure to save this data:\r\n");
            DEBUG_PRINTF("%03X # %02X %02X %02X %02X %02X %02X %02X %02X\r\n", RxMsg.identifier, RxMsg.data[0], RxMsg.data[1], RxMsg.data[2], RxMsg.data[3], RxMsg.data[4], RxMsg.data[5], RxMsg.data[6], RxMsg.data[7], RxMsg.data[8]);
          }
          if(checkFlag(CAN_startProgramming) && checkFlag(CAN_dumpingFinished) && RxMsg.data[0]==0x30){
            DEBUG_PRINTF("Got a programming accept sequence!\r\n");
          }
          if(checkFlag(CAN_startDumping) && RxMsg.data[1]==0x5A){
            DEBUG_PRINTF("Index code dump finished!\r\n");
            xQueueSend(canTxQueue, &ehu_bong_start, portMAX_DELAY);
            xQueueSend(canTxQueue, &ehu_bong_end, portMAX_DELAY);
            setFlag(CAN_dumpingFinished);
            clearFlag(CAN_startDumping);
            DEBUG_PRINTF("\r\n======== DUMPING FINISHED! ========\r\n Now press 9 for about 2 seconds to attempt the code index programming.\r\n");
            DEBUG_PRINTF("Please note that this is experimental and you're solely responsible for whatever happens.\r\n");
          }
          if(checkFlag(CAN_dumpingFinished) && RxMsg.identifier==0x641 && RxMsg.data[0]==0x30 && checkFlag(CAN_requestedCodeIndexProgramming)){
            setFlag(CAN_receivedProgrammingAllow);
          }
          if(checkFlag(CAN_receivedProgrammingAllow) && RxMsg.data[0]==0x02 && RxMsg.data[1]==0x7B && RxMsg.data[2]==0x3E){
            setFlag(CAN_programmingFinished);
          }
        } else {  // software version not yet checked, do that now
          if(checkFlag(CAN_softwareVersionRequested) && !checkFlag(CAN_softwareVersionReceived)){
            if(RxMsg.data[0]==0x10 && RxMsg.data[3]==0x7B){
              sw_day[0]=RxMsg.data[4];
              sw_day[1]=RxMsg.data[5];
              sw_month[0]=RxMsg.data[7];
            }
            if(RxMsg.data[0]==0x21){
              sw_month[1]=RxMsg.data[1];
              sw_year=RxMsg.data[6];
              setFlag(CAN_softwareVersionReceived);
            }
          }
          if(checkFlag(CAN_softwareVersionReceived) && !checkFlag(CAN_programmingFinished)){
            if((sw_day[0]==0x31 && sw_day[1]==0x30 && sw_month[0]==0x31 && sw_month[1]==0x30 && sw_year==0x37) || (sw_day[0]==0x32 && sw_day[1]==0x30 && sw_month[0]==0x30 && sw_month[1]==0x36 && sw_year==0x38)){     // either 10.10.2007 or 20.06.2008
              DEBUG_PRINTF("Detected valid software version to attempt the code index programming! Now hold 7 for 2 seconds to begin dumping the code index.\r\n");
              setFlag(CAN_softwareVersionOkay);
              ehu_force_testmode();
            } else {
              DEBUG_PRINTF("Got version %02X %02X %02X %02X %02X\r\n", sw_day[0], sw_day[1], sw_month[0], sw_month[1], sw_year);
              setFlag(CAN_softwareVersionWrong);
            }
          }
        }
        break;
      }
      default: break;
    }
  }
}

// this task receives CAN messages from canTxQueue and transmits them asynchronously
void canTransmitTask(void *pvParameters){
  static twai_message_t TxMessage;
  uint32_t alerts_triggered;
  int alert_result;
  while(1){
    xQueueReceive(canTxQueue, &TxMessage, portMAX_DELAY);
    TxMessage.extd=0;
    TxMessage.rtr=0;
    TxMessage.ss=0;
    TxMessage.self=0;
    //DEBUG_PRINTF("%03X # %02X %02X %02X %02X %02X %02X %02X %02X", TxMessage.identifier, TxMessage.data[0], TxMessage.data[1], TxMessage.data[2], TxMessage.data[3], TxMessage.data[4], TxMessage.data[5], TxMessage.data[6], TxMessage.data[7]);
    if(twai_transmit(&TxMessage, pdMS_TO_TICKS(50))==ESP_OK) {
      //DEBUG_PRINT(" Q:OK ");
    } else {
      //DEBUG_PRINT("Q:FAIL ");
      //setFlag(CAN_prevTxFail);
    }
    alert_result=twai_read_alerts(&alerts_triggered, pdMS_TO_TICKS(10));    // read stats
    if(alert_result==ESP_OK){
        //DEBUG_PRINT("AR:OK ");
      if(alerts_triggered & TWAI_ALERT_TX_SUCCESS){
        //DEBUG_PRINTLN("TX:OK ");
        if(TxMessage.identifier==0x241){ // transmitted the request for programming the code index, set the flag.
          setFlag(CAN_waitingForISO);
        }
        
      } else {
        DEBUG_PRINTLN("TX:FAIL ");
        //setFlag(CAN_prevTxFail);
      }
    } else {
        DEBUG_PRINT("AR:FAIL:");
      if(alert_result==ESP_ERR_INVALID_ARG){
        DEBUG_PRINTLN("INV_ARG");
      }
      if(alert_result==ESP_ERR_INVALID_STATE){
        DEBUG_PRINTLN("INV_STATE");
      }
      if(alert_result==ESP_ERR_TIMEOUT){
        DEBUG_PRINTLN("TIMEOUT");
      }
    }
  }
}

void indexProgrammerTask(void *pvParameters){
  DEBUG_PRINTF("IndexProgrammer: started.\r\n");
  waitForFlag(CAN_dumpingFinished);
  waitForFlag(CAN_startProgramming);
  vTaskDelay(pdMS_TO_TICKS(1000));
  #ifdef DISABLE_PROGRAMMING
  while(1){
    DEBUG_PRINTLN("PROGRAMMING DISABLED!\r\n");
    vTaskDelay(10000);
  }
  #endif
  while(1){
    setFlag(CAN_requestedCodeIndexProgramming);
    xQueueSend(canTxQueue, &codeIndex01201[0], portMAX_DELAY);
    waitForFlag(CAN_receivedProgrammingAllow);
    for(int i=1; i<26; i++){
      xQueueSend(canTxQueue, &codeIndex01201[i], portMAX_DELAY);
      vTaskDelay(pdMS_TO_TICKS(15));
    }
    waitForFlag(CAN_programmingFinished);
    DEBUG_PRINTLN("Programming finished! Now resetting the headunit...");
    vTaskDelay(pdMS_TO_TICKS(1000));
    xQueueSend(canTxQueue, &opcom_resetEHU, portMAX_DELAY);
    DEBUG_PRINTF("Headunit has been reset! Check whether Aux is available in the audio menu.");
    while(1){
      vTaskDelay(10000);
    }
  }
}

void ehu_force_testmode(){
  xQueueSend(canTxQueue, &ehu_bong_start, portMAX_DELAY);
  xQueueSend(canTxQueue, &ehu_bong_end, portMAX_DELAY);
}