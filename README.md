# UART_CODE_IMPLEMENTED_USING_PERIPHERAL_METHOD_IN_BLUEPILL_PLUS
UART :
------
#### What is UART?
a)Universal Asynchronous Receiver/Transmitter  
b)Protocol for exchanging serial data between two devices  
c)Uses only two wires  
    - Tx to Rx (each direction).     
d)Can be simplex,half-duplex, or full-duplex     
f)Data is transmitted as frames.   
### Where UART is used?  
a)UART was one of the earliest seerial protocols.  
-Serial(COM) ports,RS-232,modems etc.   
b)Popularity of UART is howerver decreasing:    
-SPI nad I2C between the components.  
-Ethernet and USB between computers and peripherals.  
c)Still important for lower-speed ,low-throughput applications.   
Bluepill Plus contain three UART's UART1, UART2,UART3.    
**Bit Rate :** Noumber of bits transmitted per second.    
**Baud Rate :** Number of signals units/symbols transmitted per second.  
**Relation Between Bitrate and Baud Rate is**   
```
Bit Rate=Baud Rate*No. of bits per symbols.  
```
**Common UART Baud Rates**   
1)4800   
2)9600   
3)19200   
4)38400      
5)11520   
6)230400     
7)460800    
8)921600    
### About timing/ sysnchronization
a)UART is asynchronous-the transmitted and receiver do not share do not share common clock.  
b)The Transmitter and Receiver therefore must:    
-Transmit at the same baud rate.   
-Use the same frame structure/parameters.   
### UART frame format
![uart frame format](https://github.com/user-attachments/assets/9906746e-e7e2-4f1b-a790-f4c5bf079a55)  
a)UART frame consists of :   
-Start/Stop bits    
-Data bits  
-Parity bit(optional)   
b)In the idle state ,the line is held high.     
### HardWare :Bluepill plus(stm32f103cbt6)  
![Screenshot 2024-12-27 191900](https://github.com/user-attachments/assets/3598a9c8-08c7-41ca-bf11-3380dd980e29) 
### UART Pins:
|S.no|UART |Pin.No |Remap Pin .No|
|---|---|---|---|
|1  |UART1_TX|PA9 |PB6 |
|   |UART1_RX|PA10 |PB7 |
|2  |UART2_TX|PA2 |PD5 (available only for 100-pin and 144-pin packages ) |
|   |UART2_RX|PA3 |PD6 (available only for 100-pin and 144-pin packages ) |
|3  |UART3_TX|PB10 |PD8 (available only for 64-pin, 100-pin and 144-pin packages)|
|   |UART3_RX|PB11 |PD9 (available only for 64-pin, 100-pin and 144-pin packages)|
### UART_BAUD_RATE_FORMULA
```
UART_DIV=(Uart_Peripheral_clock)/(Baud_Rate*16)
```
**Step-by-step Calculation:** 
Uart_Peripheral_clock=8MHz,Baud_rate=9600               
Substitute the values:UART_DIV=(80,00,000)/(9600*16).     
                              =52.0833    
**Mantissa**: Integer part of USARTDIV is 52.    
**Fraction**: Multiply the decimal part 0.0833 by 16    
                              =0.0833×16    
                              =1.333    
Round to the nearest whole number: 1.    
BRR Value:      
         Combine Mantissa and Fraction:     
         BRR=(Mantissa×16) +Fraction    
         BRR=(52×16)+1=833  
         BRR (Decimal): 833
         BRR (Hexadecimal): 0𝑥341     
