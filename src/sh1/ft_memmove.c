/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:55 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*src_cpy;

	if (!src || !dest)
		return (NULL);
	if ((src_cpy = ft_strsub(src, 0, len)))
	{
		dest = (void *)ft_strncpy(dest, src_cpy, len);
		ft_strdel(&src_cpy);
	}
	return (dest);
}
