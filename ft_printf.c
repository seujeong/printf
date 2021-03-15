#include "ft_printf.h"

int		check_type(va_list my_list, f_info *info)
{
	int		result;
	char	type;

	result = 0;
	type = info->type;
	if (type == 'c')
		result += print_char(va_arg(my_list, int), info);
	else if (type == '%')
		result += print_char('%', info);
	else if (type == 's')
		result += print_string(va_arg(my_list, char *), info);
	else if (type == 'd' || type == 'i')
		result += print_num(va_arg(my_list, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		result += print_num(va_arg(my_list, unsigned int), info);
	else if (type == 'p')
		result += print_num(va_arg(my_list, unsigned long long), info);
	return (result);
}

void	check_width_precision(va_list my_list, char *format, f_info *info, int index)
{
    if (ft_isdigit(format[index]))
	{
		if (info->precision == -1)
			info->width = info->width * 10 + format[index] - 48;
		else
			info->precision = info->precision * 10 + format[index] - 48;
	}
	else if (format[index] == '*')
	{
		if (info->precision == -1)
		{
			info->width = va_arg(my_list, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->precision = va_arg(my_list, int);
	}
}

void	check_info(va_list my_list, f_info *info, char *format, int index)
{
	if (format[index] == '0' && info->width == 0 && info->precision == -1)
		info->zero = 1;
	else if (format[index] == '-')
		info->minus = 1;
	else if (format[index] == '.')
		info->precision = 0;
	else if (ft_isdigit(format[index]) || format[index] == '*')
		check_width_precision(my_list, format, info, index);
}

int		print_format(const char *format, va_list my_list)
{
	int		index;
	int		result;
	f_info	*info;

	index = 0;
	result = 0;
	info = malloc(sizeof(f_info) * 1);
	if (!info)
		return (-1);
	while (format[index] != '\0')
	{
		while (format[index] != '%' && format[index] != '\0')
			result += ft_putchar(format[index++]);
		if (format[index] == '%')
		{
			init_info(info);
			while (format[++index] != '\0' && !ft_strchr(TYPE, format[index]));
				check_info(my_list, info, format, index);
			info->type = format[index++];
			if ((info->minus == 1 || info->precision > -1) && format[index] != '%')
				info->zero == 0;
			result += check_type(my_list, info);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	my_list;

	va_start(my_list, format);
	print_format(format, my_list);
	va_end(my_list);
	return(result);
}
