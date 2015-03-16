/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:40:54 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int		ft_string_spaces(long long len, int width, char *flags)
{
	int	nb_spaces;

	nb_spaces = 0;
	if (width != -1 && len < width)
		nb_spaces = width - len;
	else if (width <= len)
		return (0);
	while (nb_spaces)
	{
		if (flags[4] && !flags[1])
			ft_putchar('0');
		else
			ft_putchar(' ');
		nb_spaces--;
	}
	return (width - len);
}
