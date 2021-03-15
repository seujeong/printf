#include "ft_printf.h"

int		print_width(int width, int length, int zero)
{
	int		result;

	result = 0;
	while (length++ < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
	}
	return (result);
}

int		print_char(int my_list, f_info *info)
{
	int		result;
	int		length;

	length = 1;
	if (info->minus == 1)
		result += ft_putchar(my_list);
	result += print_width(info->width, length, info->zero);
	if (info->minus == 0)
		result += ft_putchar(my_list);
	return (result);
}

int		print_string(char *my_list, f_info *info)
{
	int		result;
	int		index;

	result = 0;
	index = 0;
	if (my_list == NULL)
		my_list = "(null)";
	if (info->precision == -1 || (size_t)info->precision > ft_strlen(my_list))
		info->precision = ft_strlen(my_list);
	if (info->minus == 1)
		while (info->precision-- > 0)
		{
			result += ft_putchar(my_list[index++]);
			info->width--;
		}
	result += print_width(info->width, info->precision, info->zero);
	if (info->minus == 0)
		while (info->precision-- > 0)
			result += ft_putchar(my_list[index++]);
}
