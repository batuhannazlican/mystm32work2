/*
 * GPIO.c
 *
 *  Created on: 13 Şub 2023
 *      Author: Batu
 */
#include "GPIO.h"
#include "stm32f407xx.h"
#include <stdint.h>

 static void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state);

void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state)
{


	if(state == ENABLE)
	{
		if(pGPIOx == GPIOA)
			GPIOA_CLOCK_EN();
		else if(pGPIOx == GPIOB)
			GPIOB_CLOCK_EN();
		else if(pGPIOx == GPIOC)
			GPIOC_CLOCK_EN();
		else if(pGPIOx == GPIOD)
			GPIOD_CLOCK_EN();
		else if(pGPIOx == GPIOE)
			GPIOE_CLOCK_EN();
		else if(pGPIOx == GPIOF)
			GPIOF_CLOCK_EN();
		else if(pGPIOx == GPIOG)
			GPIOG_CLOCK_EN();
		else if(pGPIOx == GPIOH)
			 GPIOH_CLOCK_EN();
		else if(pGPIOx == GPIOI)
			GPIOI_CLOCK_EN();
	}
	if(state == DISABLE)
		;
}

void gpio_init(GPIO_Handle_t *pgpio_handle)
{
	uint32_t temp=0;

	gpio_clock_en_di(pgpio_handle->pGPIOx ,ENABLE);

	// 24 ve 25.bite 01 yazmak lazım
	//1.mode seçimi yapılacak
	// 1U<<8
	temp = (pgpio_handle->gpio_pin_config.pin_mode <<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->MODER &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->MODER |=temp;

	//2.speed
	temp  = (pgpio_handle->gpio_pin_config.pin_speed << (2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OSPEEDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OSPEEDR |= temp;
	//3. otype
	temp  = (pgpio_handle->gpio_pin_config.pin_otype << (pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OTYPER &= ~(1u<<(pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OTYPER |= temp;


	//4.pupd
	temp  = (pgpio_handle->gpio_pin_config.pin_pu_pd << (2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->PUPDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->PUPDR |= temp;

	//5.alternate
	if(pgpio_handle->gpio_pin_config.pin_mode==GPIO_MODE_ALTER)
	{
		uint8_t afr_low_high =pgpio_handle->gpio_pin_config.pin_number /8 ;
		uint8_t afr_pin_no = pgpio_handle->gpio_pin_config.pin_number %8 ;

		pgpio_handle->pGPIOx->AFR[afr_low_high] &= ~(0x0F<<(4*afr_pin_no)) ;
		pgpio_handle->pGPIOx->AFR[afr_low_high] |= (pgpio_handle->gpio_pin_config.pin_alter_mode) ;
	}
}


void gpio_write_out_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no,BOOL val)
{
	if ( val == GPIO_SET)
		pgpiox->ODR |= (1u<<pin_no);
	else
		pgpiox->ODR &= ~(1u<<pin_no);
}

BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint16_t pin_no)
{

	uint16_t res =(uint16_t)((pgpiox->IDR)& (1 << pin_no));
	res = ((res != 0) ? GPIO_SET : GPIO_RESET);  // //  return (!(res)==0)
	return res;
}

void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no)
{
	pgpiox->ODR ^= (1u<<pin_no);
}

void gpio_write_port(GPIO_RegDef_t *pgpiox,uint16_t val)
{

	pgpiox->ODR =val;
}

uint16_t gpio_read_input_port(GPIO_RegDef_t *pgpiox)
{
	uint16_t val=0;
	pgpiox->IDR =0;
	val = (uint16_t)pgpiox->IDR;
	return val;
}







