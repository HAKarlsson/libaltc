#include "serio.h"

#define SERIO_UART_TI16750(_base)                                         \
	(SERIOFILE)                                                       \
	{                                                                 \
		.fputchar = uart_ti16750_fputchar,                        \
		.fgetchar = uart_ti16750_fgetchar, .base = (void *)_base, \
	}

int uart_ti16750_fputchar(int c, SERIOFILE *f);
int uart_ti16750_fgetchar(SERIOFILE *f);
