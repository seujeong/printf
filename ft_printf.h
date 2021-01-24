#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include "./libft/libft.h"

typedef struct	format_info
{
	int			width;
	int			precision;
}				f_info;

int     		ft_printf(const char *format, ...);
int     		print_format(const char *format, va_list my_list);
void    		check_width_precision(va_list my_list, char *format, f_info *info, int i);

#endif
