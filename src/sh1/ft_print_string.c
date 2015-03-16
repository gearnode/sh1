/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:41 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_get_string_len(char *arg, t_fmt *arg_fmt)
{
	if (0 <= arg_fmt->precision &&
		arg_fmt->precision < (long long)ft_strlen(arg))
		return (arg_fmt->precision);
	return ((long long)ft_strlen(arg));
}

static long long	ft_print_index_char(long long end, char *arg)
{
	int i;

	i = 0;
	while (i < end)
	{
		ft_putchar(arg[i]);
		i++;
	}
	return (end);
}

static long long	ft_putstr_string(char *arg, t_fmt *arg_fmt)
{
	if (0 <= arg_fmt->precision
		&& arg_fmt->precision < (long long)ft_strlen(arg))
		return (ft_print_index_char(arg_fmt->precision, arg));
	else
		ft_putstr(arg);
	return ((long long)ft_strlen(arg));
}

long long			ft_print_string(va_list ap, t_fmt *arg_fmt)
{
	long long	len;
	long long	nb_spaces;
	char		*arg;

	nb_spaces = 0;
	arg = va_arg(ap, char *);
	if (!arg)
		arg = "(null)";
	len = ft_get_string_len(arg, arg_fmt);
	if (!arg_fmt->flags[1])
		nb_spaces += ft_string_spaces(len, arg_fmt->width, arg_fmt->flags);
	ft_putstr_string(arg, arg_fmt);
	if (arg_fmt->flags[1])
		nb_spaces += ft_string_spaces(len, arg_fmt->width, arg_fmt->flags);
	return (len + nb_spaces);
}
