#pragma once
#include <stdarg.h>
#include <stddef.h>

typedef struct altfile ALTFILE;

struct altfile {
	int (*fputchar)(int c, ALTFILE *);
	int (*fgetchar)(ALTFILE *);
	void *base;
};

extern ALTFILE *const altout;
extern ALTFILE *const altin;

/**
 * Writes a character to an ALTFILE object.
 * @param c The character to write.
 * @param f The ALTFILE object to write to.
 * @return The result of the write operation, typically the character written or EOF on failure.
 */
int alt_fputchar(int c, ALTFILE *f);

/**
 * Reads a character from an ALTFILE object.
 * @param f The ALTFILE object to read from.
 * @return The character read, or EOF if the end of file is reached.
 */
int alt_fgetchar(ALTFILE *f);

/**
 * Writes a string to an ALTFILE object.
 * @param s The string to write.
 * @param f The ALTFILE object to write to.
 * @return The number of characters written.
 */
int alt_fputstr(const char *s, ALTFILE *f);

/**
 * Reads characters from an ALTFILE object into a string until EOF or a null character is encountered.
 * @param s The buffer to store the read characters.
 * @param size The size of the buffer.
 * @param f The ALTFILE object to read from.
 * @return The number of characters read, excluding the null terminator.
 */
int alt_fgetstr(char *s, size_t size, ALTFILE *f);

/**
 * Writes a block of data to an ALTFILE object.
 * @param s The data to write.
 * @param size The number of bytes to write.
 * @param f The ALTFILE object to write to.
 * @return The number of bytes written.
 */
int alt_fwrite(const char *s, size_t size, ALTFILE *f);

/**
 * Reads a block of data from an ALTFILE object.
 * @param s The buffer to store the read data.
 * @param size The number of bytes to read.
 * @param f The ALTFILE object to read from.
 * @return The number of bytes read.
 */
int alt_fread(char *s, size_t size, ALTFILE *f);

/**
 * Writes formatted output to an ALTFILE object.
 * @param f The ALTFILE object to write to.
 * @param format The format string.
 * @param ... Additional arguments for the format string.
 * @return The number of characters written, or a negative value on failure.
 */
int alt_fprintf(ALTFILE *f, const char *format, ...);

/**
 * Writes a character to the altout ALTFILE object.
 * @param c The character to write.
 * @return The result of the write operation, typically the character written or EOF on failure.
 */
int alt_putchar(int c);

/**
 * Reads a character from the altin ALTFILE object.
 * @return The character read, or EOF if the end of file is reached.
 */
int alt_getchar(void);

/**
 * Writes a string to the altout ALTFILE object.
 * @param s The string to write.
 * @return The number of characters written.
 */
int alt_putstr(const char *s);

/**
 * Reads characters from the altin ALTFILE object into a string.
 * @param s The buffer to store the read characters.
 * @param size The size of the buffer.
 * @return The number of characters read, excluding the null terminator.
 */
int alt_getstr(char *s, size_t size);

/**
 * Writes a block of data to the altout ALTFILE object.
 * @param s The data to write.
 * @param size The number of bytes to write.
 * @return The number of bytes written.
 */
int alt_write(const char *s, size_t size);

/**
 * Reads a block of data from the altin ALTFILE object.
 * @param s The buffer to store the read data.
 * @param size The number of bytes to read.
 * @return The number of bytes read.
 */
int alt_read(char *s, size_t size);

/**
 * Writes formatted output to the altout ALTFILE object.
 * @param format The format string.
 * @param ... Additional arguments for the format string.
 * @return The number of characters written, or a negative value on failure.
 */
int alt_printf(const char *format, ...);
