#include "altc/altio.h"

#define UART_SIFIVE(_base)                                               \
	(ALTFILE)                                                        \
	{                                                                \
		.fputchar = uart_sifive_fputchar,                        \
		.fgetchar = uart_sifive_fgetchar, .base = (void *)_base, \
	}

int uart_sifive_fputchar(int c, ALTFILE *f);
int uart_sifive_fgetchar(ALTFILE *f);
