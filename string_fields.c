#include "main.h"

/**
 * get_precision - gets percision from format string
 * @poin: format string
 * @params: parametrs struct
 * @list: arguments pointer
 * Return: new pointer
 */

char *get_precision(char *poin, params_t *params, va_list list)
{
int d = 0;
if (*poin != '.')
return (poin);
poin++;
if (*poin == '*')
{
d = va_arg(list, int);
poin++;
}
else
{
while (_isdigit(*poin))
d = d * 10 + (*poin++ - '0');
}
params->precision = d;
return (poin);
}
