/*
 * I2C.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Batu
 */

#include "I2C.h"
//PB8 SCL
//PB9 SDA

void i2c1_init()  {


	//1 clock enbale
		RCC->APB1ENR |= (1U<<21) ;
		//ALTENATE MAPPING AF4 PB8-PB9 18 19 20 21 10 OLMALI

		RCC->AHB1ENR |= (1U<<1) ; //CLOCK ENABLE

		GPIOB->MODER &= ~(1U<<16) ;
		GPIOB->MODER |=  (1U<<17) ;

		GPIOB->MODER &= ~(1U<<18) ;
		GPIOB->MODER |=  (1U<<19) ;

		//open drain
		GPIOB->OTYPER |= (1U<<8) ;
		GPIOB->OTYPER |= (1U<<9) ;



		//pull up
		GPIOB->PUPDR |=  (1U<<16) ;
		GPIOB->PUPDR &=~ (1U<<17) ;

		GPIOB->PUPDR |=  (1U<<18) ;
	    GPIOB->PUPDR &=~ (1U<<19) ;

	    //AF4

	  GPIOB->AFR[2] &= ~(1U<<0) ;
	  GPIOB->AFR[2] |=  (1U<<1) ;
	  GPIOB->AFR[2] &= ~(1U<<2) ;
	  GPIOB->AFR[2] &= ~(1U<<3) ;

	  GPIOB->AFR[2] &= ~(1U<<4) ;
	  GPIOB->AFR[2] |=  (1U<<5) ;
	  GPIOB->AFR[2] &= ~(1U<<6) ;
	  GPIOB->AFR[2] &= ~(1U<<7) ;


	  //1 clock enbale
	  RCC->APB1ENR |= (1U<<21) ;

	  I2C1->CR1 |= (1U<<15)  ;
	  I2C1->CR1 &= ~(1U<<15) ;  //I2C BİRİMİNE SOFTWARE RESET ATILDI

	  //Peripheral CLOCK
	  I2C1->CR2 |= (45<<0);

	  I2C1->CCR = 225<<0;

	  I2C1->TRISE = 46;

	  I2C1->CR1 |= (1U<<0) ;


}

	void  i2c1_start()
	{
		I2C1->CR1 |= (1<<10);  // Enable the ACK
		I2C1->CR1 |= (1<<8);  // Generate START

	}
	void I2C_Stop (void)
	{
		I2C1->CR1 |= (1<<9);  // Stop I2C
	}

	void i2c1_write( )
	{
		/*1. TXE'nin (SR1'deki bit 7) ayarlanmasını bekleyin. Bu, DR'nin boş olduğunu gösterir.
		2. VERİLERİ DR Kaydına gönderin
		3. BTF'nin (SR1'deki bit 2) ayarlanmasını bekleyin. Bu, SON VERİ aktarımının sona erdiğini gösterir.*/

		while (!(I2C1->SR1 & (1<<7)))
			;  // wait for TXE bit to set
		I2C1->DR = data;
		while (!(I2C1->SR1 & (1<<2)))
			;  // wait for BTF bit to set

	}

	void i2c1_send_adr()
	{
		/*1. Köle Adresini DR Kaydına Gönderin
		2. ADDR'nin (SR1'deki bit 1) ayarlanmasını bekleyin. Bu, adres iletiminin sonunu gösterir.
		3. SR1 ve SR2'yi okuyarak ADDR'yi silin */
		I2C1->DR = Address;  //  send the address
		while (!(I2C1->SR1 & (1<<1)))
			;  // wait for ADDR bit to set
		uint8_t temp = I2C1->SR1 | I2C1->SR2 ;
	}

void i2c1_read()
{
	int remaining = size;

	/**** STEP 1 ****/
		if (size == 1)
		{
			/**** STEP 1-a ****/
			I2C1->DR = Address;  //  send the address
			while (!(I2C1->SR1 & (1<<1)));  // wait for ADDR bit to set

			/**** STEP 1-b ****/
			I2C1->CR1 &= ~(1<<10);  // clear the ACK bit
			uint8_t temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
			I2C1->CR1 |= (1<<9);  // Stop I2C

			/**** STEP 1-c ****/
			while (!(I2C1->SR1 & (1<<6)));  // wait for RxNE to set

			/**** STEP 1-d ****/
			buffer[size-remaining] = I2C1->DR;  // Read the data from the DATA REGISTER

		}

	/**** STEP 2 ****/
		else
		{
			/**** STEP 2-a ****/
			I2C1->DR = Address;  //  send the address
			while (!(I2C1->SR1 & (1<<1)));  // wait for ADDR bit to set

			/**** STEP 2-b ****/
			uint8_t temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit

			while (remaining>2)
			{
				/**** STEP 2-c ****/
				while (!(I2C1->SR1 & (1<<6)));  // wait for RxNE to set

				/**** STEP 2-d ****/
				buffer[size-remaining] = I2C1->DR;  // copy the data into the buffer

				/**** STEP 2-e ****/
				I2C1->CR1 |= 1<<10;  // Set the ACK bit to Acknowledge the data received

				remaining--;
			}

			// Read the SECOND LAST BYTE
			while (!(I2C1->SR1 & (1<<6)));  // wait for RxNE to set
			buffer[size-remaining] = I2C1->DR;

			/**** STEP 2-f ****/
			I2C1->CR1 &= ~(1<<10);  // clear the ACK bit

			/**** STEP 2-g ****/
			I2C1->CR1 |= (1<<9);  // Stop I2C

			remaining--;

			// Read the Last BYTE
			while (!(I2C1->SR1 & (1<<6))) ;  // wait for RxNE to set
			buffer[size-remaining] = I2C1->DR ;  // copy the data into the buffer
		}

}





