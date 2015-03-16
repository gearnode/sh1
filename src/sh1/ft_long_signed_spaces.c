/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_signed_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:34:55 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_long_signed_spaces_before(t_fmt *arg_fmt, long long num_len,
			long long arg)
{
	long long nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_before_long(arg_fmt, num_len, arg);
	nb_spaces += ft_precision_zeros_long(arg_fmt, num_len);
	return (nb_spaces);
}

long long	ft_long_signed_spaces_after(t_fmt *arg_fmt, long long num_len,
			long long printed)
{
	int nb_spaces;

	nb_spaces = 0;
	nb_spaces += ft_width_spaces_after_long(arg_fmt, num_len, printed);
	return (nb_spaces);
}
