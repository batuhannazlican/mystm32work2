/*
 * gpio.h
 *
 *  Created on: 19 Oca 2023
 *      Author: Batu
 */


#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_
#include <stdint.h>
#include "stm32f407xx.h"

typedef uint8_t BOOL;

typedef struct{
	uint8_t pin_number;
	uint8_t pin_mode;
	uint8_t pin_speed;
	uint8_t pin_pu_pd;
	uint8_t pin_otype;
	uint8_t pin_alter_mode;
}GPIO_PinConfig_t;


typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t gpio_pin_config;
}GPIO_Handle_t;

// GPIO MODE STATES
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTER		2
#define GPIO_MODE_ANALOG	3

#define	GPIO_OTYPE_PP		0
#define	GPIO_OTYPE_OD		1

#define	GPIO_SPEED_LOW		0
#define	GPIO_SPEED_MED		1
#define	GPIO_SPEED_FAST		2
#define	GPIO_SPEED_VFAST	3

#define	GPIO_PUPD_NO		0
#define	GPIO_PUPD_PU		1
#define	GPIO_PUPD_PD		2

#define GPIO_PIN_0			0
#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_10			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15



void gpio_init(GPIO_Handle_t *pgpio_handle);
void gpio_write_pin(GPIO_Handle_t * handle,BOOL val);
BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no);
void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no);


#endif /* STM32F407XX_GPIO_H_ */





