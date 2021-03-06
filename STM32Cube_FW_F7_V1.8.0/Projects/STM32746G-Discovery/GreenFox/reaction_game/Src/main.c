/**
 ******************************************************************************
 * @file    Templates/Src/main.c
 * @author  MCD Application Team
 * @version V1.0.3
 * @date    22-April-2016
 * @brief   STM32F7xx HAL API Template project
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;


/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/
RNG_HandleTypeDef rnd;
unsigned int button_press_counter;
uint32_t press_timer;

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int randomnum() {
	return HAL_RNG_GetRandomNumber(&rnd);
}

void my_delay (uint32_t t) {
	for (unsigned int i = t; i > 0; i--) {
		HAL_Delay(1);
		if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == 0) {
			button_press_counter++;
			press_timer = HAL_GetTick();
		}
	}
}


int main(void) {
	/* This project template calls firstly two functions in order to configure MPU feature
	 and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
	 These functions are provided as template implementation that User may integrate
	 in his application, to enhance the performance in case of use of AXI interface
	 with several masters. */

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	/* Add your application code here
	 */
	BSP_LED_Init(LED_GREEN);
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	rnd.Instance = RNG;
	HAL_RNG_Init(&rnd);


	/* Output a message using printf function */
	printf("\n------------------WELCOME------------------\r\n");
	printf("**********in STATIC reaction game**********\r\n\n");

	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOC_CLK_ENABLE()
	;
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;
	__HAL_RCC_GPIOH_CLK_ENABLE()
	;
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;


	GPIO_InitTypeDef led1;
	led1.Pin = GPIO_PIN_6;
	led1.Mode = GPIO_MODE_OUTPUT_PP;
	led1.Pull = GPIO_PULLDOWN;
	led1.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led2;
	led2.Pin = GPIO_PIN_6;
	led2.Mode = GPIO_MODE_OUTPUT_PP;
	led2.Pull = GPIO_PULLDOWN;
	led2.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led3;
	led3.Pin = GPIO_PIN_4;
	led3.Mode = GPIO_MODE_OUTPUT_PP;
	led3.Pull = GPIO_PULLDOWN;
	led3.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led4;
	led4.Pin = GPIO_PIN_7;
	led4.Mode = GPIO_MODE_OUTPUT_PP;
	led4.Pull = GPIO_PULLDOWN;
	led4.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led5;
	led5.Pin = GPIO_PIN_0;
	led5.Mode = GPIO_MODE_OUTPUT_PP;
	led5.Pull = GPIO_PULLDOWN;
	led5.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led6;
	led6.Pin = GPIO_PIN_6;
	led6.Mode = GPIO_MODE_OUTPUT_PP;
	led6.Pull = GPIO_PULLDOWN;
	led6.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef led7;
	led7.Pin = GPIO_PIN_3;
	led7.Mode = GPIO_MODE_OUTPUT_PP;
	led7.Pull = GPIO_PULLDOWN;
	led7.Speed = GPIO_SPEED_HIGH;

	GPIO_InitTypeDef button0;
	button0.Pin = GPIO_PIN_2;
	button0.Mode = GPIO_MODE_INPUT;
	button0.Pull = GPIO_PULLUP;
	button0.Speed = GPIO_SPEED_HIGH;


	//HAL_GPIO_Init(GPIOC, &led0);
	HAL_GPIO_Init(GPIOC, &led1);
	HAL_GPIO_Init(GPIOG, &led2);
	HAL_GPIO_Init(GPIOB, &led3);
	HAL_GPIO_Init(GPIOG, &led4);
	HAL_GPIO_Init(GPIOI, &led5);
	HAL_GPIO_Init(GPIOH, &led6);
	HAL_GPIO_Init(GPIOI, &led7);
	HAL_GPIO_Init(GPIOI, &button0);


	struct LED {
		GPIO_TypeDef* LED_port;
		uint16_t LED_pin;
	};

	struct LED L1;
	L1.LED_port = GPIOC;
	L1.LED_pin = GPIO_PIN_6;
	struct LED L2;
	L2.LED_port = GPIOG;
	L2.LED_pin = GPIO_PIN_6;
	struct LED L3;
	L3.LED_port = GPIOB;
	L3.LED_pin = GPIO_PIN_4;
	struct LED L4;
	L4.LED_port = GPIOG;
	L4.LED_pin = GPIO_PIN_7;
	struct LED L5;
	L5.LED_port = GPIOI;
	L5.LED_pin = GPIO_PIN_0;
	struct LED L6;
	L6.LED_port = GPIOH;
	L6.LED_pin = GPIO_PIN_6;
	struct LED L7;
	L7.LED_port = GPIOI;
	L7.LED_pin = GPIO_PIN_3;

	struct LED led_array[7];
	//led_array[0] = L0;
	led_array[0] = L1;
	led_array[1] = L2;
	led_array[2] = L3;
	led_array[3] = L4;
	led_array[4] = L5;
	led_array[5] = L6;
	led_array[6] = L7;

	uint32_t good = 1;
	uint32_t bad = 4;
	button_press_counter = 0;

	//new working method - whack a LED type
	while (1) {
		uint32_t num = (1000 + randomnum() % 1000);
		uint32_t begin = 0;
		uint32_t reaction = 0;
		while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) != 0) {
			HAL_GPIO_WritePin(led_array[0].LED_port,led_array[0].LED_pin, GPIO_PIN_RESET);
		}
		while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == 0) {
		}
		HAL_Delay(2000);
		HAL_GPIO_WritePin(led_array[0].LED_port,led_array[0].LED_pin, GPIO_PIN_SET);
		begin = HAL_GetTick();
		my_delay(num);
		HAL_GPIO_WritePin(led_array[0].LED_port,led_array[0].LED_pin, GPIO_PIN_RESET);
		if (button_press_counter > 0) {
			HAL_GPIO_WritePin(led_array[good].LED_port,led_array[good].LED_pin, GPIO_PIN_SET);
			good++;
			reaction = press_timer - begin;
			printf("Your reaction time is: %lu ms.\n", reaction);
			button_press_counter = 0;
			if (good == 4) {
				printf("You WON!!!\nPlease reset the game!\n");
				break;
			}
		} else {
			HAL_GPIO_WritePin(led_array[bad].LED_port,led_array[bad].LED_pin, GPIO_PIN_SET);
			bad++;
			printf("Lost one life, try again!\n");
			if (bad == 7) {
				printf("You lost, you MORON!!!\nPlease reset the game!\n");
				break;
			}
		}

		// original working method - watches reacton

		/*while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) != 0) {
			HAL_GPIO_WritePin(led_array[0].LED_port,led_array[0].LED_pin, GPIO_PIN_SET);
		}
		while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == 0) {
		}
		HAL_Delay(num);
		HAL_GPIO_WritePin(led_array[0].LED_port,led_array[0].LED_pin, GPIO_PIN_RESET);
		begin = HAL_GetTick();
		while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) != 0) {
		}
		reaction = HAL_GetTick() - begin;
		printf("Your reaction time is: %u ms.\n", reaction);
		while (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == 0) {
		}

		if (reaction < 200) {
			HAL_GPIO_WritePin(led_array[good].LED_port,led_array[good].LED_pin, GPIO_PIN_SET);
			good++;
			if ()
		} else {
			HAL_GPIO_WritePin(led_array[bad].LED_port,led_array[bad].LED_pin, GPIO_PIN_SET);
			bad++;
		}*/

		HAL_Delay(3000);
	}


}
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

	return ch;
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            PLL_Q                          = 9
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
