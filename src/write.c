#include "serio.h"

int serio_write(const char *s, size_t size)
{
	size_t i;
	for (i = 0; i < size; ++i) {
		if (serio_putchar(s[i]) == EOF) {
			return -1; // Return an error code if writing fails
		}
	}
	return i; // Return the number of bytes successfully written
}
