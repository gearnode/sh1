/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:42:23 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wchar_spaces(long long arg, int width, char *flags)
{
	int		nb_spaces;
	int		len;

	len = ft_nb_bytes(arg);
	if (width <= len || width <= -1)
		return (0);
	nb_spaces = width - len;
	while (nb_spaces)
	{
		if (!flags[1] && flags[4])
			ft_putchar('0');
		else
			ft_putchar(' ');
		nb_spaces--;
	}
	return (width - len);
}
