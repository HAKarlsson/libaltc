#include "serio/ti16750.h"

#define LSR_THR_EMPTY 0x20
#define LSR_RBR_READY 0x1

struct uart_regs {
	union {
		unsigned int rbr;
		unsigned int thr;
		unsigned int dlab_lsb;
	};

	union {
		unsigned int interrupt_enable;
		unsigned int dlab_msb;
	};

	unsigned int interrupt_ident;
	unsigned int fifo_control;
	unsigned int line_control;
	unsigned int modem_control;
	unsigned int line_status;
	unsigned int modem_status;
};

void serio_ti16750_init(void *base)
{
}

int serio_ti16750_putchar(int c, void *base)
{
	volatile struct uart_regs *regs = base;
	while (!(regs->line_status & LSR_THR_EMPTY))
		;
	regs->thr = (unsigned char)c;
	return (unsigned char)c;
}

int serio_ti16750_getchar(void *base)
{
	volatile struct uart_regs *regs = base;
	while (!(regs->line_status & LSR_RBR_READY))
		;
	return (unsigned char)regs->rbr;
}
