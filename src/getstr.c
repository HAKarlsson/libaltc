#include "serio.h"

int serio_fgetstr(char *s, size_t size, SERIOFILE *f)
{
	size_t i;
	for (i = 0; i < size - 1; ++i) {
		int c = f->fgetchar(f);
		if (c == EOF || c == '\0') {
			break;
		}
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

int serio_getstr(char *s, size_t size)
{
	return serio_fgetstr(s, size, _serio_in);
}
