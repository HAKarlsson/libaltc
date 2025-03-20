#include "serio/sifive.h"

// Bit masks for transmit and receive adata registers
#define TXDATA_FULL 0x80000000ul
#define RXDATA_EMPTY 0x80000000ul

// Control register flags for enabling transmission and reception
#define TXCTRL_TXEN 0x1ul
#define RXCTRL_RXEN 0x1ul

// Control register flags for setting stop bits
#define TXCTRL_NSTOP 0x2ul

struct uart_regs {
	int txdata; // Transmit data register
	int rxdata; // Receive data register
	int txctrl; // Transmit control register
	int rxctrl; // Receive control register
	int ie;	    // UART interrupt enable
	int ip;	    // UART interrupt pending
	int div;    // Baud rate divisor
};

void serio_sifive_init(void *base)
{
}

int serio_sifive_putchar(int c, void *base)
{
	volatile struct uart_regs *regs = base;
	while (regs->txdata & TXDATA_FULL) {
	}
	regs->txdata = (unsigned char)c;
	return (unsigned char)c;
}

int serio_sifive_getchar(void *base)
{
	volatile struct uart_regs *regs = base;
	int c;
	do {
		c = regs->rxdata;
	} while (c & RXDATA_EMPTY);
	return (unsigned char)c;
}
