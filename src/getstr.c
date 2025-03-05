#include "altio.h"

int alt_fgetstr(char *s, size_t size, ALTFILE *f)
{
	size_t i;
	for (i = 0; i < size - 1; ++i) {
		int c = f->getchar(f);
		if (c == EOF || c == '\0') {
			break;
		}
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

int alt_getstr(char *s, size_t size)
{
	return alt_fgetstr(s, size, altin);
}
