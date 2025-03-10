#include "serio.h"

int serio_fread(char *s, size_t size, SERIOFILE *f)
{
	size_t i;
	for (i = 0; i < size; ++i) {
		int c = f->fgetchar(f);
		if (c == EOF) {
			break;
		}
		s[i] = (char)c;
	}
	return i; // Return the number of bytes successfully read
}

int serio_read(char *s, size_t size)
{
	return serio_fread(s, size, _serio_in);
}
