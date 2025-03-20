#include "serio.h"

int serio_putstr(const char *s)
{
	size_t i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (serio_putchar(s[i]) == EOF) {
			return -1;
		}
	}
	return i;
}
