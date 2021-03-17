/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:18:21 by seujeong          #+#    #+#             */
/*   Updated: 2021/03/16 21:28:41 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"

typedef struct	s_info
{
	char		type;
	int			width;
	int			prec;
	int			minus;
	int			zero;
	int			num_minus;
	int			num_deci;
}				t_info;

int				check_type(va_list my_list, t_info *info);
void			check_w_p(va_list my_list, char *format,
					t_info *info, int index);
void			check_info(va_list my_list, t_info *info,
					char *format, int index);
int				print_format(char *format, va_list my_list);
int				ft_printf(const char *format, ...);

int				print_width(int width, int length, int zero);
int				print_char(int my_list, t_info *info);
int				print_string(char *my_list, t_info *info);

int				set_pointer(char **buf);
int				check_minus(t_info *info, char **buf);
int				check_minus_zero(int length, t_info *info, char **buf);
int				make_buf_num(unsigned long long my_list,
					t_info *info, char **buf);
int				print_num(unsigned long long my_list, t_info *info);

void			initialize_info(t_info *info);
int				check_numlen(unsigned long long my_list, t_info *info);
char			*set_deci(char type);
int				set_width(char **buf, t_info *info);

#endif
