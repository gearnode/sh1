/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:28:30 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_replace_x(char *unicode)
{
	while (*unicode)
	{
		if (*unicode == 'x')
			*unicode = '0';
		unicode++;
	}
	return (1);
}

char	*ft_fill_unicode(char *binary, char *unicode)
{
	int		index;
	char	*mask_unicode;
	int		nb_bits;

	index = 0;
	while (unicode[index])
		index++;
	index = index - 1;
	nb_bits = ft_strlen(binary);
	while (-1 < --nb_bits)
	{
		while (unicode[index] == '1' || unicode[index] == '0' ||
			unicode[index] == ' ')
			index--;
		unicode[index] = binary[nb_bits];
		index--;
	}
	ft_replace_x(unicode);
	if (!(mask_unicode = ft_strdup(unicode)))
		return (NULL);
	return (mask_unicode);
}
