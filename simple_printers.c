#include "main.h"

/**
 * print_from_to - prints characters addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number printed bytes
 */

int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;
while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
 * print_rev - prints reversed string
 * @list: string
 * @params: parameters struct
 * Return: number printed bytes
 */

int print_rev(va_list list, params_t *params)
{
int l, sum = 0;
char *st = va_arg(list, char *);
(void)params;
if (st)
{
for (l = 0; *st ; st++)
l++;
st--;
for (; l > 0; l--, st--)
sum += _putchar(*st);
}
return (sum);
}

/**
 * print_rot13 - print string in rot13
 * @list: string
 * @params: paramters struct
 * Return: number printed bytes
 */

int print_rot13(va_list list, params_t *params)
{
int i, ind;
int coun = 0;
char arr[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLM       nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(list, char *);
(void)params;
i = 0;
ind = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
ind = a[i] - 65;
coun += _putchar(arr[ind]);
}
else
coun += _putchar(a[i]);
i++;
}
return (coun);
}
