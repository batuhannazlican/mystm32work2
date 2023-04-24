/*
 * usart.c
 *
 *  Created on: 19 Oca 2023
 *      Author: Batu
 */
#include "usart.h"
#include <stdio.h>
#include"stm32f407xx.h"


static void usart_perip_cloc_en(USART_RegDef_t *pusartx)
{



		if(pusartx == USART1)
			USART1_CLOCK_ENABLE();
		else if(pusartx == USART2)
			USART2_CLOCK_ENABLE()	;
		else if(pusartx ==USART3)
			USART3_CLOCK_ENABLE() ;
		else if(pusartx == USART4)
			USART4_CLOCK_ENABLE();
		else if(pusartx ==USART5)
			USART5_CLOCK_ENABLE();
		else if(pusartx == USART6)
			USART6_CLOCK_ENABLE();



}

uint8_t usart_get_flag_state(USART_RegDef_t *pusartx,uint8_t state_flag)
{
	if(pusartx->SR & (state_flag))
			return SET ;

	return RESET ;
}




 void usart_int(USART_Handle_t *pUsart_handle)
 {
 //burada configdeki yazdıgımız ayarları  sırayla alacağız once clock
	 	 //clock
	 usart_perip_cloc_en(pUsart_handle->pusartx) ;

	 // MODE

	 if(pUsart_handle->USART_pin_config.mode==USART_MODE_ONLY_TX)
		{
		pUsart_handle->pusartx->CR1 |= (1u<<USART_CR1_TE) ;
		}
	 else if (pUsart_handle->USART_pin_config.mode==USART_MODE_ONLY_RX)
	 {
	 pUsart_handle->pusartx->CR1 |=(1u<<USART_CR1_RE) ;

	 }
	 else if (pUsart_handle->USART_pin_config.mode==USART_MODE_BOTH_TXRX)
	 {
		 pUsart_handle->pusartx->CR1 |= (1u<<USART_CR1_TE)  | (1u<<USART_CR1_RE) ;

	 }

	 //wordlen
	 pUsart_handle->pusartx->CR1 |= (pUsart_handle->USART_pin_config.word_length) << USART_CR1_M ; //kullanıcı buraya ne girerse 1 ya 0 olacak  ardından onu kaydıracak
	 //stop bit
	 pUsart_handle->pusartx->CR1 |=(pUsart_handle->USART_pin_config.stop_bit) <<( USART_STOP_BITS_1_0 ) ;
	 //Parity
	 if (pUsart_handle->USART_pin_config.parity_control ==(USART_PARITY_NO))
	 {
		 pUsart_handle->pusartx->CR1 &= ~(1u<<USART_CR1_PCE) ;

	 }
	 else //parity var
	 {   pUsart_handle->pusartx->CR1 |= (1u<<USART_CR1_PCE) ;

	 	 if(pUsart_handle->USART_pin_config.parity_control==USART_PARITY_EVEN)
	 	 {
	 		 pUsart_handle->pusartx->CR1 &= ~(1u<<USART_CR1_PS) ;
	 	 }
	 	 else
	 	 {
	 		 pUsart_handle->pusartx->CR1 |= (1u<<USART_CR1_PS) ;
	 	 }
	 }
	 // flow control
	 if (pUsart_handle->USART_pin_config.hwflowcotrol ==USART_HW_FLOW_CONTROL_NO)
	 {
		 pUsart_handle->pusartx->CR3 &= ~(1u<<USART_CR3_RTSE) ;
		 pUsart_handle->pusartx->CR3 &= ~(1u<<USART_CR3_CTSE) ;

	 }
	 else if (pUsart_handle->USART_pin_config.hwflowcotrol == USART_HW_FLOW_CONTROL_CTS)
	 {
		 pUsart_handle->pusartx->CR3 |=  (1u<<USART_CR3_RTSE) ;
		 pUsart_handle->pusartx->CR3 &= ~(1u<<USART_CR3_CTSE) ;
	 }
	 else
	 {
		 pUsart_handle->pusartx->CR3 |=  (1u<<USART_CR3_RTSE) ;
		 pUsart_handle->pusartx->CR3 |=  (1u<<USART_CR3_CTSE) ;
	 }

 }




void uart_send_data (USART_Handle_t *pusart_Handle,uint8_t *pTxBuffer,uint32_t len)
{

     for(uint32_t i = 0 ; i < len ; ++i)
     {
    	 while(!usart_get_flag_state(pusart_Handle->pusartx,  USART_FLAG_TX)) ;
    	 // ONLY 8 Bit data transfer

    	 pusart_Handle->pusartx->DR = (*pTxBuffer) ;
    	 ++pTxBuffer ;

     }
}

void uart_receive_data (USART_Handle_t *pUsart_Handle,uint8_t *pRxBuffer,uint32_t len)

{
	for(uint32_t i = 0 ; i < len ; ++i)
	     {
	    	 while(!usart_get_flag_state(pUsart_Handle->pusartx,USART_FLAG_RXNE)) ;
	    	 // ONLY 8 Bit data transfer


	    	*pRxBuffer =  pUsart_Handle->pusartx->DR & ((uint8_t)0xFF) ;
	    	 ++pRxBuffer ;

	     }


}




