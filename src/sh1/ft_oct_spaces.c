/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:29 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_precision_zeros(t_fmt *arg_fmt, long long num_len)
{
	long long nb_zeros;

	nb_zeros = 0;
	if (num_len < arg_fmt->precision)
	{
		nb_zeros = ft_get_max(arg_fmt->precision - num_len, 0);
		ft_print_zeros_oct(nb_zeros, '0');
	}
	return (nb_zeros);
}

static long long	ft_width_spaces_before(t_fmt *arg_fmt, long long num_len,
					unsigned long long arg, long long did_0)
{
	long long nb_spaces;
	long long max;

	nb_spaces = 0;
	max = ft_get_max(arg_fmt->precision, num_len);
	if (!arg_fmt->flags[1] && max < arg_fmt->width)
	{
		nb_spaces = ft_get_max(arg_fmt->width - max - did_0, 0);
		if (arg_fmt->flags[4] &&
			(arg_fmt->precision != 0 && (arg != 0 || arg_fmt->precision == -1)
			&& (arg <= 0 || arg_fmt->precision == -1)))
			ft_print_zeros_oct(nb_spaces, '0');
		else
			ft_print_zeros_oct(nb_spaces, ' ');
	}
	return (nb_spaces);
}

static long long	ft_width_spaces_after(t_fmt *arg_fmt, long long num_len,
					unsigned long long arg, long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	if (arg_fmt->precision < arg_fmt->width && num_len < arg_fmt->width)
	{
		nb_spaces = ft_get_max(arg_fmt->width - printed, 0);
		if (arg_fmt->flags[4] && !arg_fmt->flags[1] && !(arg == 0 &&
			arg_fmt->precision != -1))
			ft_print_zeros_oct(nb_spaces, '0');
		else
			ft_print_zeros_oct(nb_spaces, ' ');
	}
	return (nb_spaces);
}

long long			ft_oct_spaces_before(t_fmt *arg_fmt, long long num_len,
					unsigned long long arg)
{
	long long nb_spaces;
	long long did_0;

	nb_spaces = 0;
	if ((did_0 = ft_needs_0_oct(arg_fmt, arg, num_len)))
		ft_print_0_before_oct(arg_fmt, arg, num_len);
	nb_spaces += ft_width_spaces_before(arg_fmt, num_len, arg, did_0);
	ft_print_0_after_oct(arg_fmt, arg, num_len);
	nb_spaces += ft_precision_zeros(arg_fmt, num_len);
	return (nb_spaces + did_0);
}

long long			ft_oct_spaces_after(t_fmt *arg_fmt, long long num_len,
					unsigned long long arg, long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_after(arg_fmt, num_len, arg, printed);
	return (nb_spaces);
}
