
/* SPI.c
 *
 *  Created on: 14 Oca 2023
 *      Author: Batu
 *//*#include "SPI.h"*/

#include "SPI.h"


/* void spi1_init()
 {
	 SPI1_CLOCK_ENABLE() ;
	 	 //BAUDRATE CONTROL
	  SPI1->CR1 |= (1U<<3) ;
	 SPI1->CR1 &= ~(1U<<4);
	 SPI1->CR1 &= ~(1U<<5);


	 //CPOL VE CPHA
	 SPI1->CR1 |=(1U<<1) ;  //CPOL
	 SPI1->CR1 |=(1U<<0) ;
	 //DFF 8 BİT
	 SPI1->CR1 &= ~(1U<<11) ;
	 //LSBFIRST Bit MSB
	 SPI1->CR1 &= ~(1U<<7)  ;


	 //software seleckt
	 //SSM=1 SSI=1 4
	SPI1->CR1 |=(1U<<8) ;
	SPI1->CR1 |=(1U<<9) ;
	//ENABLE FULL DUBLEX
	SPI1->CR1 |= (1U<<2) ; //MASTER MOD

	SPI1->CR1 &=  ~(1U<<10) ;
	//SPI ENABLE
	SPI1->CR1 |= (1U<<6) ;*/

	 //
/* }

void spi1_transmit(uint8_t *data,uint32_t size)
{
		for(uint32_t i=0 ;i<size;++i)
		{
			while(!(SPI1->SR    & (SR_TXE))) //TRASNMİT BUFFER EMPTY OALANA KADAR BEKLE
			;
			SPI1->DR = data[i] ;
			++i ;
		}
		while(!(SPI1->SR &(SR_TXE))) //EN SON BYTE GİTTİKTEN SONRA BEKLE
			;
}*/
