/* Includes ------------------------------------------------------------------*/
//#include "stm32f1xx.h"   
//#include "stm32f1xx_hal.h"
//#include "Sys.h"
//#include "gpio.h"
//#include "usart1.h"
#include "Boot0.h"
int main(void)
{
//	HAL_Init();
//	SystemClock_Config();
//	GPIO_init();
//	MX_USART1_UART_Init();
	jump_iap_app();
	while(1)
	{
//		printf("haluart1test");
//		HAL_Delay(1000);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
