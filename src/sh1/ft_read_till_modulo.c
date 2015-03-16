/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_till_modulo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:46 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_read_till_modulo(char **format)
{
	int		index;

	index = 0;
	while (**format != '\0')
	{
		if (**format != '%')
		{
			ft_putchar(**format);
			index++;
			*format = *format + 1;
		}
		else if (**format == '%' && *(*format + 1) != '%')
		{
			*format = *format + 1;
			return (index);
		}
		else if (**format == '%' && *(*format + 1) == '%')
		{
			ft_putchar(*(*format + 1));
			index++;
			*format = *format + 2;
		}
	}
	return (index);
}
