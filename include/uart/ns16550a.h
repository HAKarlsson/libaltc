#include "altio.h"

#define UART_NS16550A(_base)                                               \
	(ALTFILE)                                                          \
	{                                                                  \
		.fputchar = uart_ns16550a_fputchar,                        \
		.fgetchar = uart_ns16550a_fgetchar, .base = (void *)_base, \
	}

int uart_ns16550a_fputchar(int c, ALTFILE *f);
int uart_ns16550a_fgetchar(ALTFILE *f);
