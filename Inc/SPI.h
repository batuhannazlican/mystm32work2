/*
 * SPI.h
 *
 *  Created on: 14 Oca 2023
 *      Author: Batu
 */

#ifndef SPI_H_
#define SPI_H_
#include "stm32f407xx.h"

#define SR_TXE    (1U<<1)
#define SR_RXNE   (1U<<0)


	/* SPI CONNECTION
	 * pa4 nss
	 * pa5 clck
	 * pa6 mosı
	 * pa7 mıso

	 */

void spi1_init()  ;
void spi1_transmit(uint8_t *data,uint32_t size) ; //data : buffer olarak kullanılan size ise gönderilecek datanın boyutu

#endif /* SPI_H_ */
