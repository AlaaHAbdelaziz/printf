#include "main.h"

/**
 * init_params - clear structs and reset buf
 * @params: parametrs struct
 * @list: arguments list
 * Return: void
 */

void  init_params(params_t *params, va_list list)
{
params->unsign = 0;
params->plus_flag = 0;
params->space_flag = 0;
params->hashtag_flag = 0;
params->zero_flag = 0;
params->minus_flag = 0;
params->width = 0;
params->precision = UINT_MAX;
params->h_modifier = 0;
params->l_modifier = 0;
(void)list;
}
