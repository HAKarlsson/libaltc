#include "altio.h"

int alt_fputstr(const char *s, ALTFILE *f)
{
	size_t i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (f->fputchar(s[i], f) == EOF) {
			return -1;
		}
	}
	return i;
}

int alt_putstr(const char *s)
{
	return alt_fputstr(s, altout);
}
