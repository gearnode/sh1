/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:39:11 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_stock_specifier(char **format, char *specifier, char converter)
{
	char	*list;

	list = "sSpdDioOuUxXcCfFb";
	if (**format == '\0')
		return (0);
	while (*list)
	{
		if (**format == *list)
		{
			*specifier = *list;
			if (*specifier == 'c' && converter == 'l')
				*specifier = 'C';
			if (*specifier == 's' && converter == 'l')
				*specifier = 'S';
			*format = *format + 1;
			return (1);
		}
		list++;
	}
	return (0);
}
