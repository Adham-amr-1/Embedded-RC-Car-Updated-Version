#include "USART.h"

void UART_vInit(u32 BAUD_RATE)
{
	// Set TX, RX Pins
	DIO_Set_Pin_Direction(PORT_D, PIN_NO_0, INPUT);
	DIO_Set_Pin_Direction(PORT_D, PIN_NO_1, OUTPUT);
#if defined NORMAL_SPEED
	Set_Normal_Asynchronous_Mode();
#elif defined HIGH_SPEED
	Set_Double_Speed_Asynchronous_Mode();
#endif
	// SET The Baud Rate
	u16 UBRR = (F_CPU/(16*BAUD_RATE)) - 1;
	UBRRH = (u8)UBRR>>8;
	UBRRL = (u8)UBRR;
	// Enable TX, RX
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	// Set Number of bits
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}
void UART_Send_Data(u8 DATA)
{
	// Check if the Data Register of the TX is there's data or not
	while(READ_BIT(UCSRA,UDRE) == 0);
	UDR = DATA;
}
void UART_Send_String(u8* DATA)
{
	while(*DATA != 0)
	{
		UART_Send_Data(*DATA);
		DATA++;
		_delay_ms(100);
	}
}
u8 UART_u8Receive_Data()
{
	// Check if there's Received on RX Buffer exist or not
	while(READ_BIT(UCSRA,RXC) == 0);
	return UDR;
}
// Happens when the data rate is different ( Data over Run )
u8 UART_DOR_Check()
{
	return READ_BIT(UCSRA,DOR);
}
// Check The Parity Error
u8 UART_PE_Check()
{
	return READ_BIT(UCSRA,PE);
}
// Check Frame Error
u8 UART_FE_Check()
{
	return READ_BIT(UCSRA,FE);
}
void Set_Normal_Asynchronous_Mode()
{
	CLEAR_BIT(UCSRA,U2X);
}
void Set_Double_Speed_Asynchronous_Mode()
{
	SET_BIT(UCSRA,U2X);
}
void Set_UARTRX_Interrupt()
{
	SET_BIT(UCSRB,RXCIE);
}
void Clear_UARTRX_Interrupt()
{
	CLEAR_BIT(UCSRB,RXCIE);
}














