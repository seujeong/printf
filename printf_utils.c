#include "ft_printf.h"

void	initialize_info(f_info *info)
{
	info->type = 0;
	info->width = 0;
	info->precision = -1;
	info->minus = 0;
	info->zero = 0;
	info->num_minus = 1;
	info->num_deci = 10;
}

int		check_numlen(unsigned long long my_list, f_info *info)
{
	int		index;

	if (my_list == 0 && info->precision != 0)
		return (1);
	index = 0;
	while (my_list)
	{
		index++;
		my_list /= info->num_deci;
	}
	return (index);
}

char	*deci_set(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
