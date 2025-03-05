#include "altio.h"

int alt_fwrite(const char *s, size_t size, ALTFILE *f)
{
	size_t i;
	for (i = 0; i < size; ++i) {
		if (f->fputchar(s[i], f) == EOF) {
			return -1; // Return an error code if writing fails
		}
	}
	return i; // Return the number of bytes successfully written
}

int alt_write(const char *s, size_t size, ALTFILE *f)
{
	return alt_fwrite(s, size, altout);
}
