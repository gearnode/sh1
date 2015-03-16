/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 11:52:24 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 12:49:32 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void		ft_free_array(char **array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char		*check_path(char **paths, char **parse_exec)
{
	int			i;
	char		*path_ret;

	i = -1;
	while (paths[++i])
	{
		path_ret = join_env(paths[i], "/", parse_exec[0]);
		if (access(path_ret, X_OK) == 0)
		{
			ft_free_array(paths);
			return (path_ret);
		}
		free(path_ret);
	}
	return (NULL);
}

char			*get_path(t_env *e, char **parse_exec)
{
	int				index;
	char			*path_cpy;
	char			**paths;
	char			*ret;

	if (!parse_exec[0])
		return (NULL);
	if (access(parse_exec[0], X_OK) == 0)
		return (parse_exec[0]);
	if (get_env(e, "PATH") == -1)
		return (NULL);
	index = get_env(e, "PATH=");
	path_cpy = ft_strdup(e->env[index]);
	path_cpy += 5;
	paths = ft_strsplit(path_cpy, ':');
	ret = check_path(paths, parse_exec);
	return (ret);
}
