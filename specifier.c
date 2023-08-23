#include "main.h"

/**
 * get_specifier - finds the format func
 * @st : format string
 * Return: number f printed bytes
 */

int (*get_specifier(char *st))(va_list list, params_t *params)
{
specifier_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_s},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};
int r = 0;
while (specifiers[r].specifier)
{
if (*st == specifiers[r].specifier[0])
{
return (specifiers[r].f);
}
r++;
}
return (NULL);
}

/**
 * get_print_func - finds the format func
 * @st: format string
 * @list: arguments pointer
 * @params: parameters struct
 * Return: number of printed bytes
 */

int get_print_func(char *st, va_list list, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(st);
if (f)
return (f(list, params));
return (0);
}

/**
 * get_flag - finds the flag function
 * @st: format string
 * @params: parameters struct
 * Return: valid flag
 */

int get_flag(char *st, params_t *params)
{
int i = 0;
switch (*st)
{
case '+':
i = params->plus_flag = 1;
break;
case ' ':
i = params->space_flag = 1;
break;
case '#':
i = params->hashtag_flag = 1;
break;
case '-':
i = params->minus_flag = 1;
break;
case '0':
i = params->zero_flag = 1;
break;
}
return (i);
}

/**
 * get_modifier - finds the modifier function
 * @st: format string
 * @params: parameters struct
 * Return: valid modifier
 */

int get_modifier(char *st, params_t *params)
{
int i = 0;
switch (*st)
{
case 'h':
i = params->h_modifier = 1;
break;
case 'l':
i = params->l_modifier = 1;
break;
}
return (i);
}

/**
 * get_width - gets width from format string
 * @st: format string
 * @params: parameters struct
 * @list: list of arguments
 * Return: pointer
 */

char *get_width(char *st, params_t *params, va_list list)
{
int d = 0;
if (*st == '*')
{
d = va_arg(list, int);
st++;
}
else
{
while (_isdigit(*st))
d = d * 10 + (*st++ - '0');
}
params->width = d;
return (st);
}
