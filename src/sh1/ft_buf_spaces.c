/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:24:05 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_buf_spaces(int width, int b_index, char *flags)
{
	int	nb_spaces;

	nb_spaces = 0;
	if (width != -1 && b_index < width)
		nb_spaces = width - b_index;
	else if (width <= b_index)
		return (0);
	while (nb_spaces)
	{
		if (flags[4])
			ft_putchar('0');
		else
			ft_putchar(' ');
		nb_spaces--;
	}
	return (width - b_index);
}
