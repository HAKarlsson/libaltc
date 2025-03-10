#include "serio.h"

#define SERIO_UART_NS16550A(_base)                                         \
	(SERIOFILE)                                                        \
	{                                                                  \
		.fputchar = uart_ns16550a_fputchar,                        \
		.fgetchar = uart_ns16550a_fgetchar, .base = (void *)_base, \
	}

int uart_ns16550a_fputchar(int c, SERIOFILE *f);
int uart_ns16550a_fgetchar(SERIOFILE *f);
