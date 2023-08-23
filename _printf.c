#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: is a character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
int sum;
va_list list;
char *poin, *start;
params_t params = PARAMS_INIT;
va_start(list, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (poin = (char *) format; *poin ; poin++)
{
init_params(&params, list);
if (*poin != '%')
{
sum += _putchar(*poin);
continue;
}
start = poin;
poin++;
while (get_flag(poin, &params))
{
poin++;
}
poin = get_width(poin, &params, list);
poin = get_precision(poin, &params, list);
if (get_modifier(poin, &params))
poin++;
if (!get_specifier(poin))
sum += print_from_to(start, poin,
params.l_modifier || params.h_modifier ? poin - 1 : 0);
else
sum += get_print_func(poin, list, &params);
}
_putchar(BUF_FLUSH);
va_end(list);
return (sum);
}
