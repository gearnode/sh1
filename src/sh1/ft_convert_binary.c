/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:24:47 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_convert_binary(char *mask_unicode)
{
	int		*bin;
	int		index;
	char	**unicode;

	unicode = ft_strsplit(mask_unicode, ' ');
	bin = (int *)malloc(sizeof(int) * 4);
	index = 0;
	while (index < 4 && unicode[index])
	{
		bin[index] = ft_atoi(unicode[index]);
		index++;
	}
	while (index < 4)
	{
		bin[index] = -42;
		index++;
	}
	return (bin);
}
