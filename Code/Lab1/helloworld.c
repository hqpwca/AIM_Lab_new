#include "uart.h"

extern void uart_init();

void port_out(unsigned short port, unsigned char data)
{
	/* TODO: Using Assembly of C to output 8-bit data to the port given. */

	asm volatile("out %0,%1" : : "a" (data), "d" (port));
}

void main(void)
{
	/* TODO: 
	 *	1. Using the given function to initialize the uart serial port.
	 *	2. Output the string "Hello, World." to the port above.
	 *	3. Using Assembly or C code to make the program in cycle
	 */

	uart_init();

	char a[20] = "Hello, World.";
	int i;

	for(i=0; a[i]!='\0'; i++)
		port_out(UART_BASE + UART_TRANS_HOLD, a[i]);

	asm volatile("hlt");
}