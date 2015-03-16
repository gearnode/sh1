/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:51 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_fmt(t_fmt *arg_format)
{
	int	i;

	i = 0;
	while (i++ < 5)
		arg_format->flags[i] = '\0';
	arg_format->width = -1;
	arg_format->precision = -1;
	arg_format->specifier = '\0';
	arg_format->converter = '\0';
	arg_format->star = '\0';
}
