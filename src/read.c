#include "serio.h"

int serio_read(char *s, size_t size)
{
	size_t i;
	for (i = 0; i < size; ++i) {
		int c = serio_getchar();
		if (c == EOF) {
			break;
		}
		s[i] = (char)c;
	}
	return i; // Return the number of bytes successfully read
}
