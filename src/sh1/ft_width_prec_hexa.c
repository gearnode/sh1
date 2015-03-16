/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:42:27 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_print_zeros_hexa(long long nb_spaces, char a)
{
	long long i;

	i = 0;
	while (i < nb_spaces)
	{
		ft_putchar(a);
		i++;
	}
	return (i);
}

long long			ft_precision_zeros_hexa(t_fmt *arg_fmt, long long num_len)
{
	long long nb_zeros;

	nb_zeros = 0;
	if (num_len < arg_fmt->precision)
	{
		nb_zeros = ft_get_max(arg_fmt->precision - num_len, 0);
		ft_print_zeros_hexa(nb_zeros, '0');
	}
	return (nb_zeros);
}

long long			ft_width_spaces_before_hexa(t_fmt *arg_fmt,
					long long num_len, unsigned long long arg, long long did_0x)
{
	long long nb_spaces;
	long long max;

	nb_spaces = 0;
	max = 0;
	if ((ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
		!arg_fmt->flags[1] && (!arg_fmt->flags[4] ||
		arg_fmt->specifier == 'x' || arg_fmt->specifier == 'X' ||
		arg_fmt->specifier == 'p')) ||
		(arg_fmt->width == -1 && arg_fmt->precision == -1))
	{
		max = ft_get_max(arg_fmt->precision, num_len);
		nb_spaces = ft_get_max(arg_fmt->width - max - did_0x, 0);
		if (arg_fmt->flags[4] && !arg_fmt->flags[1] &&
			!(arg == 0 && arg_fmt->precision != -1) &&
			!(ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
			0 < arg && arg_fmt->precision != -1))
			ft_print_zeros_hexa(nb_spaces, '0');
		else
			ft_print_zeros_hexa(nb_spaces, ' ');
	}
	return (nb_spaces);
}

long long			ft_width_spaces_after_hexa(t_fmt *arg_fmt,
					long long num_len, unsigned long long arg,
					long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	if (arg_fmt->precision < arg_fmt->width && num_len < arg_fmt->width)
	{
		nb_spaces = ft_get_max(arg_fmt->width - printed, 0);
		if (arg_fmt->flags[4] && !arg_fmt->flags[1] &&
			arg_fmt->precision != 0 && !(arg == 0 && arg_fmt->precision != -1))
			ft_print_zeros_hexa(nb_spaces, '0');
		else
			ft_print_zeros_hexa(nb_spaces, ' ');
	}
	return (nb_spaces);
}
