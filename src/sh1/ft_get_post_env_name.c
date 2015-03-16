/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_post_env_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:44:09 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:48:52 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char		*ft_get_post_env_name(char *post_env)
{
	char	*name;
	int		i;

	i = 0;
	while (post_env[i] && post_env[i] != '=')
		i++;
	name = ft_strsub(post_env, 0, i);
	return (name);
}
