/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:45:53 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:46:00 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char	*join_env(char const *s1, char const *s2, char const *s3)
{
	char	*s_new;
	size_t	len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	if (!(s_new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			s_new[i] = s1[i];
		else if (i < ft_strlen(s1) + ft_strlen(s2))
			s_new[i] = s2[i - ft_strlen(s1)];
		else
			s_new[i] = s3[i - ft_strlen(s1) - ft_strlen(s2)];
		i++;
	}
	return (s_new);
}
