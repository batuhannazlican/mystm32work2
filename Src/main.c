/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f407xx.h"
#include "usart.h"
#include <string.h>
#include "usart.h"
#include "GPIO.h"


/*void usart_int()
{
		USART_Handle_t usart1_handle ;
		usart1_handle.pusartx=USART1 ;
		usart1_handle.USART_pin_config.mode = USART_MODE_BOTH_TXRX ;
		usart1_handle.USART_pin_config.word_length=USART_WORDLEN_8BITS ;
		usart1_handle.USART_pin_config.stop_bit=USART_STOP_BITS_1_0 ;
		usart1_handle.USART_pin_config.hwflowcotrol=USART_HW_FLOW_CONTROL_NO ;

*/

int main(void)
{





}

	/*USART_Handle_t usart1_handle ;
	usart1_handle.pusartx=USART1 ;
	usart1_handle.USART_pin_config.mode = USART_MODE_BOTH_TXRX ;
	usart1_handle.USART_pin_config.word_length=USART_WORDLEN_8BITS ;
	usart1_handle.USART_pin_config.stop_bit=USART_STOP_BITS_1_0 ;
	usart1_handle.USART_pin_config.hwflowcotrol=USART_HW_FLOW_CONTROL_NO ;
//	uart1_handle.UART_pin_config.baudrate =

	char str[]= "batuhan_message" ;

	uart_init(&usart1_handle) ;

	uart_send1_data(&usart1_handle, (uint8_t*)str,str len(str)) ; //bu bfufferdan veriyi alıcam burası buffer */



		/*GPIO_Handle_t gpioLed12 = {GPIOD,{GPIO_PIN_12,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
		GPIO_Handle_t gpioLed13 = {GPIOD,{GPIO_PIN_13,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
		GPIO_Handle_t gpioLed14 = {GPIOD,{GPIO_PIN_14,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
		GPIO_Handle_t gpioLed15 = {GPIOD,{GPIO_PIN_15,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}}; */


		/*gpio_init(&gpioLed12);
		gpio_init(&gpioLed13);
		gpio_init(&gpioLed14);
		gpio_init(&gpioLed15); */

		/*GPIO_Handle_t  nsspin= {GPIOA , {GPIO_PIN_4,GPIO_MODE_ALTER,GPIO_SPEED_MED,GPIO_PUPD_NO,GPIO_OTYPE_PP,GPIO_AF5}};
		GPIO_Handle_t clkpin= {GPIOA , {GPIO_PIN_5,GPIO_MODE_ALTER,GPIO_SPEED_MED,GPIO_PUPD_NO,GPIO_OTYPE_PP,GPIO_AF5}};
		GPIO_Handle_t misopin= {GPIOA , {GPIO_PIN_6,GPIO_MODE_ALTER,GPIO_SPEED_MED,GPIO_PUPD_NO,GPIO_OTYPE_PP,GPIO_AF5}};
		GPIO_Handle_t mosipin= {GPIOA , {GPIO_PIN_7,GPIO_MODE_ALTER,GPIO_SPEED_MED,GPIO_PUPD_NO,GPIO_OTYPE_PP,GPIO_AF5}};*/

	/*
  	   gpio_init(&nsspin);
				gpio_init(&clkpin);
				gpio_init(&misopin);
				gpio_init(&mosipin);*/


	/*			char str_data[] = "ABC" ;
		spi1_init() ;

	while(1)
	{
				///ŞUAN BURADA HATA VAR ANCAK KABLO GELİNCE DUZENLEYEEĞİM
			spi1_transmit((uint8_t*)str_data,strlen(str_data)) ;
	}
	}
*/





   /*RCC->AHB1ENR |= (1U<<3 ) ; */
   /* (1U<<12) ;GPIOD->MODER |= (1U<<24) ;
   GPIOD->ODR  = (1U<<12) ;

  //   * * Loop forever */

