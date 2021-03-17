/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:21:16 by seujeong          #+#    #+#             */
/*   Updated: 2021/03/16 21:32:04 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		print_char(int my_list, t_info *info)
{
	int		result;
	int		length;

	length = 1;
	result = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		result += ft_putchar(my_list);
	result += print_width(info->width, length, info->zero);
	if (info->minus == 0)
		result += ft_putchar(my_list);
	return (result);
}

int		print_string(char *my_list, t_info *info)
{
	int		result;
	int		index;

	result = 0;
	index = 0;
	if (my_list == NULL)
		my_list = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(my_list))
		info->prec = ft_strlen(my_list);
	if (info->minus == 1)
	{
		while (info->prec-- > 0)
		{
			result += ft_putchar(my_list[index++]);
			info->width--;
		}
		info->prec += 1;
	}
	result += print_width(info->width, info->prec, info->zero);
	if (info->minus == 0)
		while (info->prec-- > 0)
			result += ft_putchar(my_list[index++]);
	return (result);
}
