/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_post_env_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:44:33 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:48:08 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char		*ft_get_post_env_value(char *post_env)
{
	char	*value;

	while (*post_env != '=')
		post_env++;
	while (*post_env && (*post_env == '=' || ft_is_space(*post_env)))
		post_env++;
	value = ft_strsub(post_env, 0, ft_strlen(post_env));
	return (value);
}
