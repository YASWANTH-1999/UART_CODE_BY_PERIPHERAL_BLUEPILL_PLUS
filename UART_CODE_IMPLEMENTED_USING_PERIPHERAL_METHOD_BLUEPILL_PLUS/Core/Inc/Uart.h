/*
 * Uart.h
 *
 *  Created on: Jan 9, 2025
 *      Author: MadaYaswanth
 */

#ifndef INC_UART_H_
#define INC_UART_H_


#include"unistd.h"




#define BAUD_RATE_UART_4800  4800
#define BAUD_RATE_UART_9600  9600
#define BAUD_RATE_UART_19200  19200
#define BAUD_RATE_UART_38400  38400
#define BAUD_RATE_UART_1152000  11520
#define BAUD_RATE_UART_230400  230400
#define BAUD_RATE_UART_460800  460800
#define BAUD_RATE_UART_921600  921600


void uart1_pin_settings(void);
void uart1_init(void);
unsigned int Calculate_Baud_Rate(unsigned int,unsigned int);
void uart1_tx(uint8_t);

#endif /* INC_UART_H_ */
