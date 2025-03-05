#include "serio.h"

int serio_fgetchar(SERIOFILE *f)
{
	return f->fgetchar(f);
}

int serio_getchar(void)
{
	return serio_fgetchar(altin);
}
