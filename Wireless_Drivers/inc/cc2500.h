/**
  ******************************************************************************
  * @file    cc2500.h
  * @author  Jit Kanetkar, Stephen Carter / Based on the LIS3DSH driver by TA Ashraf
  * @version V1.0.0
  * @date    11th-November-2015
  * @brief   Used to communicate with the CC2500 wireless chip. Uses SPI2.
  ******************************************************************************
	**/
#ifndef _INCLUDE_CC2500_H_
#define _INCLUDE_CC2500_H_

/* includes */
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"

/* data structures */

/* enums */
typedef enum {
	CC2500_PARTNAME = 0x30,
	CC2500_VERSION = 0x31,
} CC2500_REG;

typedef enum {
	CC2500_SPI_CLK = GPIO_Pin_13,
	CC2500_SPI_MISO = GPIO_Pin_14,
	CC2500_SPI_MOSI = GPIO_Pin_15,
	CC2500_SPI_CS = GPIO_Pin_12
}	CC2500_SPI_Pin;

/* defines */
#define CC2500_FLAG_TIMEOUT 						 ((uint32_t)0x1000)

#define CC2500_SPI                       SPI2
#define CC2500_SPI_CLK                   RCC_APB1Periph_SPI2

#define CC2500_SPI_SCK_PIN               GPIO_Pin_13                 /* PA.05 */
#define CC2500_SPI_SCK_GPIO_PORT         GPIOB                       /* GPIOA */
#define CC2500_SPI_SCK_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define CC2500_SPI_SCK_SOURCE            GPIO_PinSource13
#define CC2500_SPI_SCK_AF                GPIO_AF_SPI2

#define CC2500_SPI_MISO_PIN              GPIO_Pin_14                 /* PA.6 */
#define CC2500_SPI_MISO_GPIO_PORT        GPIOB                       /* GPIOA */
#define CC2500_SPI_MISO_GPIO_CLK         RCC_AHB1Periph_GPIOB
#define CC2500_SPI_MISO_SOURCE           GPIO_PinSource14
#define CC2500_SPI_MISO_AF               GPIO_AF_SPI2

#define CC2500_SPI_MOSI_PIN              GPIO_Pin_15                 /* PA.7 */
#define CC2500_SPI_MOSI_GPIO_PORT        GPIOB                       /* GPIOA */
#define CC2500_SPI_MOSI_GPIO_CLK         RCC_AHB1Periph_GPIOB
#define CC2500_SPI_MOSI_SOURCE           GPIO_PinSource15
#define CC2500_SPI_MOSI_AF               GPIO_AF_SPI2

#define CC2500_SPI_CS_PIN                GPIO_Pin_12                 /* PE.03 */
#define CC2500_SPI_CS_GPIO_PORT          GPIOB                       /* GPIOE */
#define CC2500_SPI_CS_GPIO_CLK           RCC_AHB1Periph_GPIOB

#define CC2500_SPI_INT1_PIN              GPIO_Pin_0                  /* PE.00 */
#define CC2500_SPI_INT1_GPIO_PORT        GPIOE                       /* GPIOE */
#define CC2500_SPI_INT1_GPIO_CLK         RCC_AHB1Periph_GPIOE
#define CC2500_SPI_INT1_EXTI_LINE        EXTI_Line0
#define CC2500_SPI_INT1_EXTI_PORT_SOURCE EXTI_PortSourceGPIOE
#define CC2500_SPI_INT1_EXTI_PIN_SOURCE  EXTI_PinSource0
#define CC2500_SPI_INT1_EXTI_IRQn        EXTI0_IRQn 

#define CC2500_SPI_INT2_PIN              GPIO_Pin_1                  /* PE.01 */
#define CC2500_SPI_INT2_GPIO_PORT        GPIOE                       /* GPIOE */
#define CC2500_SPI_INT2_GPIO_CLK         RCC_AHB1Periph_GPIOE
#define CC2500_SPI_INT2_EXTI_LINE        EXTI_Line1
#define CC2500_SPI_INT2_EXTI_PORT_SOURCE EXTI_PortSourceGPIOE
#define CC2500_SPI_INT2_EXTI_PIN_SOURCE  EXTI_PinSource1
#define CC2500_SPI_INT2_EXTI_IRQn        EXTI1_IRQn 

/* functions */
int CC2500_SPI_INIT(void);
void CC2500_Read(uint8_t* pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead);
#endif // _INCLUDE_CC2500_H_
