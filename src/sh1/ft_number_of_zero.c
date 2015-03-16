/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:18 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_number_of_zero(t_fmt *arg_fmt, int num_len)
{
	if (!arg_fmt->flags[1] && arg_fmt->flags[4] &&
		arg_fmt->precision <= -1 && num_len < arg_fmt->width)
		return (arg_fmt->width - num_len - 1);
	if (num_len < arg_fmt->precision)
		return (arg_fmt->precision - num_len);
	return (0);
}
