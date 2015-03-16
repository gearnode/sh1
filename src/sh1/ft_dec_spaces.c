/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:28:26 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_precision_zeros_dec(t_fmt *arg_fmt, long long num_len)
{
	long long nb_zeros;

	nb_zeros = 0;
	if (num_len < arg_fmt->precision)
	{
		nb_zeros = ft_get_max(arg_fmt->precision - num_len, 0);
		ft_print_zeros_dec(nb_zeros, '0');
	}
	return (nb_zeros);
}

static long long	ft_width_spaces_before_dec(t_fmt *arg_fmt,
					long long num_len, unsigned long long arg)
{
	long long nb_spaces;
	long long max;

	nb_spaces = 0;
	max = 0;
	if ((ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
		!arg_fmt->flags[1] && (!arg_fmt->flags[4] || arg != 0)) ||
		(arg_fmt->width == -1 && arg_fmt->precision == -1) ||
		(arg == 0 && arg_fmt->precision != -1 &&
		ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
		!arg_fmt->flags[1]))
	{
		max = ft_get_max(arg_fmt->precision, num_len);
		nb_spaces = ft_get_max(arg_fmt->width - max, 0);
		if (arg_fmt->flags[4] && !arg_fmt->flags[1] &&
			!(arg == 0 && arg_fmt->precision != -1 &&
			ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width) &&
			!(ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
			arg_fmt->precision != -1 && 0 < arg))
			ft_print_zeros_dec(nb_spaces, '0');
		else
			ft_print_zeros_dec(nb_spaces, ' ');
	}
	return (nb_spaces);
}

static long long	ft_width_spaces_after_dec(t_fmt *arg_fmt, long long num_len,
					long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	if (ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width)
	{
		nb_spaces = ft_get_max(arg_fmt->width - printed, 0);
		if (arg_fmt->flags[4] && !arg_fmt->flags[1] && arg_fmt->precision != 0)
			ft_print_zeros_dec(nb_spaces, '0');
		else
			ft_print_zeros_dec(nb_spaces, ' ');
	}
	return (nb_spaces);
}

long long			ft_dec_spaces_before(t_fmt *arg_fmt, long long num_len,
					unsigned long long arg)
{
	long long nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_before_dec(arg_fmt, num_len, arg);
	nb_spaces += ft_precision_zeros_dec(arg_fmt, num_len);
	return (nb_spaces);
}

long long			ft_dec_spaces_after(t_fmt *arg_fmt, long long num_len,
					long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_after_dec(arg_fmt, num_len, printed);
	return (nb_spaces);
}
