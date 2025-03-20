#include "serio/uart/ti16750.h"

#define LSR_THR_EMPTY 0x20
#define LSR_RBR_READY 0x1

struct uart_regs {
	union {
		uint32_t rbr;
		uint32_t thr;
		uint32_t dlab_lsb;
	};

	union {
		uint32_t interrupt_enable;
		uint32_t dlab_msb;
	};

	uint32_t interrupt_ident;
	uint32_t fifo_control;
	uint32_t line_control;
	uint32_t modem_control;
	uint32_t line_status;
	uint32_t modem_status;
};

void uart_ti16750_init(SERIOFILE *f)
{
}

int uart_ti16750_fputchar(int c, SERIOFILE *f)
{
	volatile struct uart_regs *base = f->base;
	while (!(base->line_status & LSR_THR_EMPTY))
		;
	base->thr = (unsigned char)c;
	return (unsigned char)c;
}

int uart_ti16750_fgetchar(SERIOFILE *f)
{
	volatile struct uart_regs *base = f->base;
	while (!(base->line_status & LSR_RBR_READY))
		;
	return (unsigned char)base->rbr;
}
