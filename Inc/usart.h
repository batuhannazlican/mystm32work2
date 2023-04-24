/*
 * usart.h
 *
 *  Created on: 19 Oca 2023
 *      Author: Batu
 */

#ifndef USART_H_
#define USART_H_
#include "stm32f407xx.h"

enum{
		USART_CR1_SBK,
		USART_CR1_RWU,
		USART_CR1_RE,
		USART_CR1_TE,
		USART_CR1_IDLEIE,
		USART_CR1_RXNEIE,
		USART_CR1_TCIE,
		USART_CR1_TXEIE,
		USART_CR1_PEIE,
		USART_CR1_PS,
		USART_CR1_PCE,
		USART_CR1_WAKE,
		USART_CR1_M,
		USART_CR1_UE,
		USART_CR1_OVER8,

};

enum{
	USART_CR2_ADD,
	USART_CR2_LBDL=5,
	USART_CR2_LBDIEL,
	USART_CR2_LBCL=8,
	USART_CR2_CPHA,
	USART_CR2_CPOL,
	USART_CR2_CLKEN,
	USART_CR2_STOP,
	USART_CR2_LINEN=14,

} ;

enum {
	USART_CR3_EIE,
	USART_CR3_IREN,
	USART_CR3_IRLP,
	USART_CR3_HDSEL,
	USART_CR3_NACK,
	USART_CR3_SCEN,
	USART_CR3_DMAR,
	USART_CR3_DMAT,
	USART_CR3_RTSE,
	USART_CR3_CTSE,
	USART_CR3_CTSIE,
	USART_CR3_ONEBIT,

};


enum {
		USART_SR_PE,
		USART_SR_FE,
		USART_SR3_NF,
		USART_SR_ORE,
		USART_SR_IDLEK,
		USART_SR_RXNE,
		USART_SR_TC,
		USART_SR_TXNE,
		USART_SR_LBD,
		USART_SR_CTS,


};

//usart flags

#define USART_FLAG_TX (1<<USART_SR_TXNE)
#define USART_FLAG_RXNE		 (1<<USART_SR_RXNE)
#define USAT_FLAG_TC       (1<<USART_SR_TC)

//modes
#define USART_MODE_ONLY_TX       0
#define USART_MODE_ONLY_RX	     1
#define USART_MODE_BOTH_TXRX 	 2

//word length
#define USART_WORDLEN_8BITS 0
#define USART_WORDLEN_9BITS 1
//STOP BIT
#define USART_STOP_BITS_0_5   	1
#define USART_STOP_BITS_1_0 	0
#define USART_STOP_BITS_1_5  	2
#define USART_STOP_BITS_2_0     3
//PARITIY
#define USART_PARITY_NO   0
#define USART_PARITY_EVEN 1
#define USART_PARITY_ODD  2
// HARDWARE FLOW CONTROL
#define USART_HW_FLOW_CONTROL_NO  0
#define USART_HW_FLOW_CONTROL_CTS 1
#define USART_HW_FLOW_CONTROL_RTS 2
#define USART_HW_FLOW_CONTROL_CTS_RTS  3







typedef struct{
	uint8_t mode;
	uint8_t  word_length;
	uint8_t stop_bit;
	uint8_t baudrate;
	uint8_t parity_control;
	uint8_t hwflowcotrol;
}USART_Config_t;


typedef struct{
	USART_RegDef_t *pusartx;
	USART_Config_t USART_pin_config;
}USART_Handle_t;





 void uart_int(USART_Handle_t *pUsart_handle) ;
 void uart_send_data (USART_Handle_t *pUsart_Handle,uint8_t *pTxBuffer,uint32_t len)  ;
 void uart_receive_data (USART_Handle_t *pUsart_Handle,uint8_t *pRxBuffer,uint32_t len) ;




#endif /* USART_H_ */
