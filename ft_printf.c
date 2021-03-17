/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:15:54 by seujeong          #+#    #+#             */
/*   Updated: 2021/03/16 21:26:12 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(va_list my_list, t_info *info)
{
	int		result;
	char	type;

	result = 0;
	type = info->type;
	if (type == 'c')
		result = print_char(va_arg(my_list, int), info);
	else if (type == '%')
		result = print_char('%', info);
	else if (type == 's')
		result = print_string(va_arg(my_list, char *), info);
	else if (type == 'd' || type == 'i')
		result = print_num(va_arg(my_list, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		result = print_num(va_arg(my_list, unsigned int), info);
	else if (type == 'p')
		result = print_num(va_arg(my_list, unsigned long long), info);
	return (result);
}

void	check_w_p(va_list my_list, char *format, t_info *info, int index)
{
	if (ft_isdigit(format[index]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[index] - 48;
		else
			info->prec = info->prec * 10 + format[index] - 48;
	}
	else if (format[index] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(my_list, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(my_list, int);
	}
}

void	check_info(va_list my_list, t_info *info, char *format, int index)
{
	if (format[index] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[index] == '-')
		info->minus = 1;
	else if (format[index] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[index]) || format[index] == '*')
		check_w_p(my_list, format, info, index);
}

int		print_format(char *format, va_list my_list)
{
	int		index;
	int		result;
	t_info	*info;

	index = 0;
	result = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (format[index] != '\0')
	{
		while (format[index] != '%' && format[index] != '\0')
			result += ft_putchar(format[index++]);
		if (format[index] == '%')
		{
			initialize_info(info);
			while (format[++index] != '\0' && !ft_strchr(TYPE, format[index]))
				check_info(my_list, info, format, index);
			info->type = format[index++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			result += check_type(my_list, info);
		}
	}
	free(info);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	my_list;

	va_start(my_list, format);
	result = print_format((char *)format, my_list);
	va_end(my_list);
	return (result);
}
