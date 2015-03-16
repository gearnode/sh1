/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:39:06 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_return_precision(char **format)
{
	char	*num;
	int		i;
	int		precision_cpy;

	i = 0;
	*format = *format + 1;
	while (ft_isdigit(**format))
	{
		*format = *format + 1;
		i++;
	}
	num = ft_strsub(*format - i, 0, i);
	precision_cpy = ft_atoi(num);
	free(num);
	return (precision_cpy);
}

int			ft_stock_precision(char **format, t_fmt *arg_fmt)
{
	if (**format == '.')
	{
		arg_fmt->precision = ft_return_precision(format);
		return (1);
	}
	return (0);
}
