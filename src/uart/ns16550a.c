#include "serio/ns16550a.h"

// Line status register flags
#define LSR_RX_READY 0x1  // Receive data ready
#define LSR_TX_READY 0x60 // Transmit data ready

struct uart_regs {
	union {
		char rbr; // Receiver buffer register (read only)
		char thr; // Transmitter holding register (write only)
	};

	char ier; // Interrupt enabler register

	union {
		char iir; // Interrupt identification register (read only)
		char fcr; // FIFO control register (write only)
	};

	char lcr; // Line control register
	char __padding;
	char lsr; // Line status register
};

void serio_ns16550a_init(void *base)
{
}

int serio_ns16550a_putchar(int c, void *base)
{
	volatile struct uart_regs *regs = base;
	while (!(regs->lsr & LSR_TX_READY))
		;
	regs->thr = (unsigned char)c;
	return (unsigned char)c;
}

int serio_ns16550a_getchar(void *base)
{
	volatile struct uart_regs *regs = base;
	while (!(regs->lsr & LSR_RX_READY))
		;
	return (unsigned char)regs->rbr;
}
