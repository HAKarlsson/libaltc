#include "serio.h"

#define UART_SIFIVE(_base)                                               \
	(SERIOFILE)                                                      \
	{                                                                \
		.fputchar = uart_sifive_fputchar,                        \
		.fgetchar = uart_sifive_fgetchar, .base = (void *)_base, \
	}

int uart_sifive_fputchar(int c, SERIOFILE *f);
int uart_sifive_fgetchar(SERIOFILE *f);
