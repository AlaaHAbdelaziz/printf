#include "main.h"

/**
 * _puts - prints string + new line
 * @str: printed string
 * Return: void
 */

int _puts(char *str)
{
char *s = str;
while (*str)
_putchar(*str++);
return (str - s);
}


/**
 * _putchar - writes the char to stdout
 * @c: char to print
 * Return: 1 success, -1 failed
 */

int _putchar(int c)
{
static int n;
static char buf[OUTPUT_BUF_SIZE];
if (c == BUF_FLUSH || n >= OUTPUT_BUF_SIZE)
{
write(1, buf, n);
n = 0;
}
if (c != BUF_FLUSH)
buf[n++] = c;
return (1);
}
