/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:29:47 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_hexa_spaces_before(t_fmt *arg_fmt, long long num_len,
			unsigned long long arg)
{
	long long nb_spaces;
	long long did_0x;

	nb_spaces = 0;
	if ((did_0x = ft_needs_0x(arg_fmt, arg)))
		ft_print_0x_before(arg_fmt, arg, num_len);
	nb_spaces += ft_width_spaces_before_hexa(arg_fmt, num_len, arg, did_0x);
	ft_print_0x_after(arg_fmt, arg, num_len);
	nb_spaces += ft_precision_zeros_hexa(arg_fmt, num_len);
	return (nb_spaces + did_0x);
}

long long	ft_hexa_spaces_after(t_fmt *arg_fmt, long long num_len,
			unsigned long long arg, long long printed)
{
	long long nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_after_hexa(arg_fmt, num_len, arg, printed);
	return (nb_spaces);
}
