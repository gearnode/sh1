/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:42:31 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_needs_sign_before(t_fmt *arg_fmt, long long arg)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->flags[2])
			i++;
	}
	if (0 < arg && arg_fmt->flags[2])
		i++;
	if (arg < 0 && arg != LONG_MIN)
		i++;
	return (i);
}

static long long	ft_print_zeros_int(long long nb_spaces, char a)
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

long long			ft_precision_zeros_int(t_fmt *arg_fmt, long long num_len)
{
	long long nb_zeros;

	nb_zeros = 0;
	if (num_len < arg_fmt->precision)
	{
		nb_zeros = (arg_fmt->precision - num_len);
		ft_print_zeros_int(nb_zeros, '0');
	}
	return (nb_zeros);
}

long long			ft_width_spaces_before_int(t_fmt *arg_fmt,
					long long num_len, long long arg)
{
	long long	nb_spaces;
	long long	max;
	long long	sign;
	long long	space;

	sign = 0;
	max = ft_get_max(arg_fmt->precision, num_len);
	if ((sign = ft_needs_sign_before(arg_fmt, arg)))
		ft_print_sign_before_int(arg_fmt, arg, num_len);
	space = ft_print_space_before_int(arg_fmt, arg);
	if (arg_fmt->flags[1])
		nb_spaces = 0;
	else
		nb_spaces = ft_get_max(arg_fmt->width - max - sign - space, 0);
	if (ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
		!arg_fmt->flags[1])
	{
		if (!arg_fmt->flags[4] ||
			(arg_fmt->precision < arg_fmt->width && arg_fmt->precision != -1))
			ft_print_zeros_int(nb_spaces, ' ');
		else if (arg_fmt->flags[4] || (arg == 0 && arg_fmt->precision == -1))
			ft_print_zeros_int(nb_spaces, '0');
	}
	ft_print_sign_after_int(arg_fmt, arg, num_len);
	return (nb_spaces + sign + space);
}

long long			ft_width_spaces_after_int(t_fmt *arg_fmt, long long num_len,
					long long printed)
{
	long long	nb_spaces;

	nb_spaces = ft_get_max(arg_fmt->width - printed, 0);
	if (ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width)
	{
		if (arg_fmt->flags[4] && !arg_fmt->flags[1])
			ft_print_zeros_int(nb_spaces, '0');
		else
			ft_print_zeros_int(nb_spaces, ' ');
	}
	return (nb_spaces);
}
