/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:39:18 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_return_width(char **format)
{
	char	*num;
	int		i;
	int		width;

	i = 0;
	while (ft_isdigit(**format))
	{
		i++;
		*format = *format + 1;
	}
	num = ft_strsub(*format - i, 0, i);
	width = ft_atoi(num);
	return (width);
}

int			ft_stock_width(char **format, t_fmt *arg_fmt)
{
	if (*(*format - 1) != '.' && **format != '0' && ft_isdigit(**format))
	{
		arg_fmt->width = ft_return_width(format);
		return (1);
	}
	return (0);
}
