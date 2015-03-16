/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:41:18 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*s_new;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (!(s_new = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			s_new[i] = (*f)(i, s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}
