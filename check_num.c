/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:21:10 by seujeong          #+#    #+#             */
/*   Updated: 2021/03/16 21:27:51 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_pointer(char **buf)
{
	*buf = ft_strjoin("0x", *buf);
	return (ft_strlen(*buf));
}

int		check_minus(t_info *info, char **buf)
{
	int		minus_size;
	char	*temp;

	minus_size = 0;
	if ((info->type == 'i' || info->type == 'd') &&
					info->zero == 0 && info->num_minus == -1)
	{
		temp = ft_strjoin("-", *buf);
		free(*buf);
		*buf = temp;
		minus_size = 1;
	}
	return (minus_size);
}

int		check_minus_zero(int length, t_info *info, char **buf)
{
	int		minus_size;
	char	*temp;

	minus_size = 0;
	if (info->num_minus == -1 && info->zero == 1)
	{
		if (length >= info->width)
		{
			temp = ft_strjoin("-", *buf);
			free(*buf);
			*buf = temp;
			minus_size = 1;
		}
		else if (length < info->width)
			*buf[0] = '-';
	}
	return (minus_size);
}

int		make_buf_num(unsigned long long my_list, t_info *info, char **buf)
{
	int		i;
	int		num_len;
	int		result;

	i = 0;
	result = check_numlen(my_list, info);
	num_len = (info->prec > result) ? info->prec : result;
	if (!(*buf = (char *)malloc(sizeof(char) * num_len + 1)))
		return (0);
	(*buf)[num_len] = '\0';
	while (result + i < num_len)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (my_list == 0 && info->prec != 0)
		(*buf)[num_len - i] = '0';
	while (my_list)
	{
		(*buf)[num_len - i] = set_deci(info->type)[my_list % info->num_deci];
		my_list /= info->num_deci;
		i++;
	}
	return (result);
}

int		print_num(unsigned long long my_list, t_info *info)
{
	char	*buf;
	int		result;
	int		buf_temp;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->num_deci = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)my_list < 0)
	{
		info->num_minus = -1;
		my_list = -my_list;
	}
	buf_temp = make_buf_num(my_list, info, &buf);
	buf_temp += check_minus(info, &buf);
	if (info->type == 'p')
	{
		set_pointer(&buf);
	}
	result = set_width(&buf, info);
	result += check_minus_zero(buf_temp, info, &buf);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (result);
}
