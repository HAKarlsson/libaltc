#pragma once
#include <stdarg.h>
#include <stddef.h>

#ifndef EOF
#define EOF (-1)
#endif /* EOF */

typedef struct seriofile SERIOFILE;

struct seriofile {
	int (*fputchar)(int c, SERIOFILE *);
	int (*fgetchar)(SERIOFILE *);
	void *base;
};

extern SERIOFILE *const altout;
extern SERIOFILE *const altin;

/**
 * Writes a character to an SERIOFILE object.
 * @param c The character to write.
 * @param f The SERIOFILE object to write to.
 * @return The result of the write operation, typically the character written or EOF on failure.
 */
int serio_fputchar(int c, SERIOFILE *f);

/**
 * Reads a character from an SERIOFILE object.
 * @param f The SERIOFILE object to read from.
 * @return The character read, or EOF if the end of file is reached.
 */
int serio_fgetchar(SERIOFILE *f);

/**
 * Writes a string to an SERIOFILE object.
 * @param s The string to write.
 * @param f The SERIOFILE object to write to.
 * @return The number of characters written.
 */
int serio_fputstr(const char *s, SERIOFILE *f);

/**
 * Reads characters from an SERIOFILE object into a string until EOF or a null character is encountered.
 * @param s The buffer to store the read characters.
 * @param size The size of the buffer.
 * @param f The SERIOFILE object to read from.
 * @return The number of characters read, excluding the null terminator.
 */
int serio_fgetstr(char *s, size_t size, SERIOFILE *f);

/**
 * Writes a block of data to an SERIOFILE object.
 * @param s The data to write.
 * @param size The number of bytes to write.
 * @param f The SERIOFILE object to write to.
 * @return The number of bytes written.
 */
int serio_fwrite(const char *s, size_t size, SERIOFILE *f);

/**
 * Reads a block of data from an SERIOFILE object.
 * @param s The buffer to store the read data.
 * @param size The number of bytes to read.
 * @param f The SERIOFILE object to read from.
 * @return The number of bytes read.
 */
int serio_fread(char *s, size_t size, SERIOFILE *f);

/**
 * Writes formatted output to an SERIOFILE object.
 * @param f The SERIOFILE object to write to.
 * @param format The format string.
 * @param ... Additional arguments for the format string.
 * @return The number of characters written, or a negative value on failure.
 */
int serio_fprintf(SERIOFILE *f, const char *format, ...);

int serio_vfprintf(SERIOFILE *F, const char *format, va_list ap);

/**
 * Writes a character to the altout SERIOFILE object.
 * @param c The character to write.
 * @return The result of the write operation, typically the character written or EOF on failure.
 */
int serio_putchar(int c);

/**
 * Reads a character from the altin SERIOFILE object.
 * @return The character read, or EOF if the end of file is reached.
 */
int serio_getchar(void);

/**
 * Writes a string to the altout SERIOFILE object.
 * @param s The string to write.
 * @return The number of characters written.
 */
int serio_putstr(const char *s);

/**
 * Reads characters from the altin SERIOFILE object into a string.
 * @param s The buffer to store the read characters.
 * @param size The size of the buffer.
 * @return The number of characters read, excluding the null terminator.
 */
int serio_getstr(char *s, size_t size);

/**
 * Writes a block of data to the altout SERIOFILE object.
 * @param s The data to write.
 * @param size The number of bytes to write.
 * @return The number of bytes written.
 */
int serio_write(const char *s, size_t size);

/**
 * Reads a block of data from the altin SERIOFILE object.
 * @param s The buffer to store the read data.
 * @param size The number of bytes to read.
 * @return The number of bytes read.
 */
int serio_read(char *s, size_t size);

/**
 * Writes formatted output to the altout SERIOFILE object.
 * @param format The format string.
 * @param ... Additional arguments for the format string.
 * @return The number of characters written, or a negative value on failure.
 */
int serio_printf(const char *format, ...);

int serio_vprintf(const char *format, va_list ap);
