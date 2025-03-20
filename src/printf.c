#include "serio.h"

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

int serio_printf(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int length = serio_vprintf(fmt, ap);
	va_end(ap);
	return length;
}

void _print_hex(unsigned long long x)
{
	if (!x) {
		serio_putchar('0');
		return;
	}

	char hex[16];
	int i = 0;
	while (x) {
		unsigned int h = x % 16;
		if (h < 10)
			hex[i++] = '0' + h;
		else
			hex[i++] = 'A' + h - 10;
		x >>= 4;
	}
	while (i) {
		serio_putchar(hex[--i]);
	}
}

void _print_dec(unsigned long long x, bool neg)
{
	if (!x) {
		serio_putchar('0');
		return;
	}

	char dec[32];
	int i = 0;
	while (x) {
		dec[i++] = '0' + (x % 10);
		x /= 10;
	}
	if (neg)
		dec[i++] = '-';

	while (i) {
		serio_putchar(dec[--i]);
	}
}

int serio_vprintf(const char *fmt, va_list ap)
{
	while (*fmt != '\0') {
		if (*fmt != '%') {
			serio_putchar(*fmt);
			fmt++;
			continue;
		}
		fmt++;
		if (*fmt == '\0')
			break;
		switch (*fmt) {
		case 'x': {
			unsigned int x = va_arg(ap, unsigned int);
			_print_hex(x);
		} break;
		case 'X': {
			unsigned long long x = va_arg(ap, unsigned long long);
			_print_hex(x);
		} break;
		case 'u': {
			unsigned int x = va_arg(ap, unsigned int);
			_print_dec(x, false);
		} break;
		case 'U': {
			unsigned long long x = va_arg(ap, unsigned long long);
			_print_dec(x, false);
		} break;
		case 'd': {
			int x = va_arg(ap, unsigned int);
			bool neg = x < 0;
			_print_dec(neg ? -x : x, neg);
		} break;
		case 'D': {
			long long x = va_arg(ap, unsigned long long);
			bool neg = x < 0;
			_print_dec(neg ? -x : x, neg);
		} break;
		case 'c': {
			char c = va_arg(ap, int);
			serio_putchar(c);
		} break;
		case 's': {
			char *s = va_arg(ap, char *);
			serio_putstr(s);
		} break;
		default:
			serio_putchar(*fmt);
		}
		fmt++;
	}
	/* TODO: return number of characters written. */
	return 0;
}
