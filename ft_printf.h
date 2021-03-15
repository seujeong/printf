#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include ".\libft\libft.h"

# define TYPE "csdiupxX%"

typedef struct	format_info
{
	char		type;
	int			width;
	int			precision;
	int			minus;
	int			zero;
	int			num_minus;
	int			num_deci;
}				f_info;

int				ft_printf(const char *format, ...);
int				print_format(const char *format, va_list my_list);
void			check_width_precision(va_list my_list, char *format, f_info *info, int i);

void			initialize_info(f_info *info);
int				check_numlen(unsigned long long my_list, f_info *info);
char			*deci_set(char type);

#endif
