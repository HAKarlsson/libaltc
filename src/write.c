#include "serio.h"

int serio_fwrite(const char *s, size_t size, SERIOFILE *f)
{
	size_t i;
	for (i = 0; i < size; ++i) {
		if (f->fputchar(s[i], f) == EOF) {
			return -1; // Return an error code if writing fails
		}
	}
	return i; // Return the number of bytes successfully written
}

int serio_write(const char *s, size_t size)
{
	return serio_fwrite(s, size, altout);
}
