/* Private typedef -----------------------------------------------------------*/
extern UART_HandleTypeDef hlpuart1;
extern SPI_HandleTypeDef hspi1;
extern uint8_t divider;


uint8_t divider = 0;
char buffer[50];
uint8_t size = 0;

osThreadId Slow_TaskHandle;
osThreadId Fast_TaskHandle;
osSemaphoreId BinSemHandle;

void MX_FREERTOS_Init(void) {
  /* definition and creation of BinSem */
  osSemaphoreDef(BinSem);
  BinSemHandle = osSemaphoreCreate(osSemaphore(BinSem), 1);

  /* definition and creation of Slow_Task */
  osThreadDef(Slow_Task, Start_Slow_Task, osPriorityBelowNormal,0,128);
  Slow_TaskHandle = osThreadCreate(osThread(Slow_Task), NULL);

  /* definition and creation of Fast_Task */
  osThreadDef(Fast_Task, Start_Fast_Task, osPriorityAboveNormal,0,128);
  Fast_TaskHandle = osThreadCreate(osThread(Fast_Task), NULL);

  HAL_TIM_Base_Start_IT(&htim3);
}

void Start_Slow_Task(void const * argument)
{
  /* Infinite loop */
	osDelay(100);
  for(;;)
  {
	  if(divider >= 2) { 
		  //NAV_SendUartAngles(&nav, &hlpuart1);	// IMU 3D viz
		  NAV_SendUartRawFrame(&nav, &hlpuart1);	// Data logger
		  
		  divider = 0;
	  }
	  osDelay(10);
  }
}

void Start_Fast_Task(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
	  osSemaphoreWait(BinSemHandle, osWaitForever);
	  divider ++;
	  NAV_Step(&nav, &hspi1, &hlpuart1);
  }
}
