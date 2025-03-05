#include "serio.h"

int serio_fputchar(int c, SERIOFILE *f)
{
	return f->fputchar(c, f);
}

int serio_putchar(int c)
{
	return serio_fputchar(c, altout);
}
