#include "serio.h"

int serio_getstr(char *s, size_t size)
{
	size_t i;
	for (i = 0; i < size - 1; ++i) {
		int c = serio_getchar();
		if (c == EOF || c == '\0') {
			break;
		}
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}
