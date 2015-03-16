/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zeros_oct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:57 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_needs_0_oct(t_fmt *arg_fmt, unsigned long long arg,
			long long num_len)
{
	if (arg == 0 && arg_fmt->flags[0])
	{
		if (arg_fmt->precision == 0)
			return (1);
	}
	if (0 < arg && arg_fmt->flags[0])
	{
		if (arg_fmt->precision <= num_len)
			return (1);
	}
	return (0);
}

long long	ft_print_0_before_oct(t_fmt *arg_fmt, unsigned long long arg,
			long long num_len)
{
	if (arg == 0 && arg_fmt->flags[0])
	{
		if (arg_fmt->precision == 0 && arg_fmt->width <= 1)
		{
			ft_putchar('0');
			return (1);
		}
	}
	if (0 < arg && arg_fmt->flags[0])
	{
		if (!arg_fmt->flags[4] &&
			arg_fmt->width < ft_get_max(arg_fmt->precision, num_len))
		{
			ft_putchar('0');
			return (1);
		}
		else if (arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) <= arg_fmt->width)
		{
			ft_putchar('0');
			return (1);
		}
	}
	return (0);
}

long long	ft_print_0_after_oct(t_fmt *arg_fmt, unsigned long long arg,
			long long num_len)
{
	if (arg == 0 && arg_fmt->flags[0])
	{
		if (arg_fmt->precision == 0 && 1 < arg_fmt->width)
		{
			ft_putchar('0');
			return (1);
		}
	}
	if (arg != 0 && arg_fmt->flags[0])
	{
		if (!arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) <= arg_fmt->width)
		{
			ft_putchar('0');
			return (1);
		}
		else if (arg_fmt->flags[4] &&
			arg_fmt->width < ft_get_max(arg_fmt->precision, num_len) &&
			arg_fmt->precision <= num_len)
		{
			ft_putchar('0');
			return (1);
		}
	}
	return (0);
}

long long	ft_print_zeros_oct(long long nb_spaces, char a)
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
