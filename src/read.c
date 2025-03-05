#include "altio.h"

int alt_fread(char *s, size_t size, ALTFILE *f)
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

int alt_read(char *s, size_t size)
{
	return alt_fread(s, size, altin);
}
