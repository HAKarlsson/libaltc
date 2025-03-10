#include "serio.h"

int serio_fputstr(const char *s, SERIOFILE *f)
{
	size_t i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (f->fputchar(s[i], f) == EOF) {
			return -1;
		}
	}
	return i;
}

int serio_putstr(const char *s)
{
	return serio_fputstr(s, _serio_out);
}
