#include "ft_printf.h"

int		set_pointer(char **buf)
{
	*buf = ft_strjoin("0x", *buf);
	return (ft_strlen(*buf));
}

int		check_minus(f_info *info)
{
	int		minus_size;

	minus_size = 0;
	if ((info->type == 'i' || info->type == 'd') && info->num_minus == -1)
	{
		write(1, "=", 1);
		minus_size = 1;
	}
	return (minus_size);
}

int		check_minus_zero(int length, f_info *info, char **buf)
{
	int		minus_size;

	minus_size = 0;
	if (info->num_minus == -1 && info->zero == 1)
	{
		if (length >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			minus_size = 1;
		}
		else if (minus_size < info->width)
			*buf[0] = '-';
	}
	return (minus_size);
}

int		make_buf(unsigned long long my_list, f_info *info, char **buf)
{
	int		index;
	int		result;
	int		num_length;

	index = 0;
	num_length = check_numlen(my_list, info);
	result = info->precision > num_length ? info->precision : num_length;
	if (!(*buf = (char *)malloc(sizeof(char) * result + 1)))
		return (0);
	(*buf)[result] = '\0';
	while (num_length + index < result)
	{
		(*buf)[index] = '0';
		index++;
	}
	index = 1;
	if (my_list == 0 && info->precision != 0)
		(*buf)[result - index] = '0';
	while (my_list)
	{
		(*buf)[result - index] = deci_set(info->type)[my_list % info->num_deci];
		my_list /= info->num_deci;
		index++;
	}
	return (num_length);
}

int		print_num(unsigned long long my_list, f_info *info)
{
	int		result;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->num_deci = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)my_list < 0)
	{
		info->num_minus = -1;
		my_list = -my_list;
	}
}
