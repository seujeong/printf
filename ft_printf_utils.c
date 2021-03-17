/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:19:48 by seujeong          #+#    #+#             */
/*   Updated: 2021/03/16 21:26:45 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_info(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->prec = -1;
	info->minus = 0;
	info->zero = 0;
	info->num_minus = 1;
	info->num_deci = 10;
}

int		check_numlen(unsigned long long my_list, t_info *info)
{
	int		index;

	if (my_list == 0 && info->prec != 0)
		return (1);
	index = 0;
	while (my_list)
	{
		index++;
		my_list /= info->num_deci;
	}
	return (index);
}

char	*set_deci(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int		set_width(char **buf, t_info *info)
{
	int		index;
	char	*width;
	char	*temp;

	index = 0;
	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	while ((index < info->width - (int)ft_strlen(*buf)))
	{
		width[index] = (info->zero == 1) ? '0' : ' ';
		index++;
	}
	width[index] = '\0';
	if (info->minus == 0)
		temp = ft_strjoin(width, *buf);
	else
		temp = ft_strjoin(*buf, width);
	*buf = temp;
	free(width);
	return (info->width);
}
