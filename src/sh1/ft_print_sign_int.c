/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:25 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_add_sign_int_before(t_fmt *arg_fmt,
			long long arg, long long num_len, long long i)
{
	if (0 < arg && arg_fmt->flags[2])
	{
		if (arg_fmt->width <= ft_get_max(arg_fmt->precision, num_len) + 1)
			ft_put_sign('+', &i);
		if (arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			arg_fmt->precision == -1)
			ft_put_sign('+', &i);
	}
	else if (arg < 0 && arg != LONG_MIN)
	{
		if (arg_fmt->flags[4] && arg_fmt->precision == -1)
			ft_put_sign('-', &i);
		else if (arg_fmt->width <= num_len && arg_fmt->precision <= num_len)
			ft_put_sign('-', &i);
		else if (num_len < arg_fmt->precision &&
			arg_fmt->width <= arg_fmt->precision + 1)
			ft_put_sign('-', &i);
		else if (ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			arg_fmt->flags[0])
			ft_put_sign('-', &i);
		else if (arg_fmt->flags[1] && (!arg_fmt->flags[0] ||
			arg_fmt->width <= ft_get_max(arg_fmt->precision, num_len) + 1))
			ft_put_sign('-', &i);
	}
}

long long		ft_print_sign_before_int(t_fmt *arg_fmt, long long arg,
				long long num_len)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->flags[2] && arg_fmt->precision == -1)
			ft_put_sign('+', &i);
	}
	if ((0 < arg && arg_fmt->flags[2]) || (arg < 0 && arg != LONG_MIN))
		ft_add_sign_int_before(arg_fmt, arg, num_len, i);
	return (i);
}

static void		ft_add_sign_int_after(t_fmt *arg_fmt, long long arg,
				long long num_len)
{
	if (arg < 0 && arg != LONG_MIN && !arg_fmt->flags[1])
	{
		if (ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			!arg_fmt->flags[4])
			ft_putchar('-');
		else if (arg_fmt->precision <= num_len && arg_fmt->precision != -1 &&
			num_len < arg_fmt->width)
			ft_putchar('-');
		else if (ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			arg_fmt->precision != -1)
			ft_putchar('-');
	}
	else if (0 < arg && arg_fmt->flags[2])
	{
		if (ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width &&
			!arg_fmt->flags[4])
			ft_putchar('+');
		else if (arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			arg_fmt->precision != -1)
			ft_putchar('+');
	}
}

long long		ft_print_sign_after_int(t_fmt *arg_fmt, long long arg,
				long long num_len)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->flags[2] && arg_fmt->precision != -1)
			ft_put_sign('+', &i);
	}
	if ((arg < 0 && arg != LONG_MIN) || (0 < arg && arg_fmt->flags[2]))
		ft_add_sign_int_after(arg_fmt, arg, num_len);
	return (i);
}
