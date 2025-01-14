/*
 * Uart.c
 *
 *  Created on: Jan 9, 2025
 *      Author: MadaYaswanth
 */


#include"Uart.h"
#include"main.h"
#include"math.h"
#include"unistd.h"
void uart1_pin_settings(void)
{
	//Clock for Uart1 PA9=TX,PA10=RX
	RCC->APB2ENR|=(1<<14);
	//clock for Gpioa
	RCC->APB2ENR|=(1<<2);
	//set pa9 as Alternate function push-pull
	GPIOA->CRH|=0XA0;
    //pa10 as Input floating / Input pull-up
	GPIOA->CRH|=0X800;
}
void uart1_init(void)
{
	//Baud Rate calculation in uart
	USART1->BRR|=Calculate_Baud_Rate(BAUD_RATE_UART_9600,16);
	//Enable TX,RX,UART
	USART1->CR1|=1<<2|1<<3|1<<13;
}
void uart1_tx(uint8_t sending_char_is_byte)
{
	while(!(USART1->SR>>7&1));
	USART1->DR=(sending_char_is_byte&0xff);

}
unsigned int Calculate_Baud_Rate(unsigned int Baud_Rate,unsigned int Over_Sampling)
{
float USART_DIV=(float)SystemCoreClock/(Baud_Rate*Over_Sampling);
// Extract Mantissa and Fraction
unsigned int mantissa = (unsigned int)USART_DIV;
unsigned int fraction = (unsigned int)round((USART_DIV - mantissa) * Over_Sampling);

// Combine Mantissa and Fraction to form BRR
return (mantissa << 4) | (fraction & 0xF);
}
