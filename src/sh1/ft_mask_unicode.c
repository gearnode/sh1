/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:26 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mask_unicode(unsigned long long n)
{
	char	*unicode[4];
	char	*binary;
	char	*mask_unicode;

	mask_unicode = NULL;
	unicode[0] = ft_strdup("0xxxxxxx");
	unicode[1] = ft_strdup("110xxxxx 10xxxxxx");
	unicode[2] = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	unicode[3] = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	binary = ft_itobase(n, 2);
	if (ft_nb_bytes(n) == 1)
		mask_unicode = ft_fill_unicode(binary, unicode[0]);
	else if (ft_nb_bytes(n) == 2)
		mask_unicode = ft_fill_unicode(binary, unicode[1]);
	else if (ft_nb_bytes(n) == 3)
		mask_unicode = ft_fill_unicode(binary, unicode[2]);
	else if (ft_nb_bytes(n) == 4)
		mask_unicode = ft_fill_unicode(binary, unicode[3]);
	ft_free_unicode(unicode[0], unicode[1], unicode[2], unicode[3]);
	return (mask_unicode);
}
