/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:56:49 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 16:32:01 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void		check_env(t_env *e)
{
	char **pwd_add;

	pwd_add = (char **)malloc(sizeof(char *) * 3 + 1);
	if (get_env(e, "PWD") == -1)
	{
		pwd_add[0] = "bryan";
		pwd_add[1] = "PWD";
		pwd_add[2] = getcwd(0, 0);
		new_env(e, pwd_add);
	}
	if (get_env(e, "OLDPWD") == -1)
	{
		pwd_add[0] = "nadjib";
		pwd_add[1] = "OLDPWD";
		pwd_add[2] = getcwd(0, 0);
		new_env(e, pwd_add);
	}
}

static void		tild_dir(t_env *e, char **args)
{
	char		*dir;
	int			oldpwd;
	int			pwd;
	int			home;

	if ((home = get_env(e, "HOME")) == -1)
	{
		ft_printf("env HOME is not define");
		return ;
	}
	oldpwd = get_env(e, "OLDPWD");
	pwd = get_env(e, "PWD");
	ft_memdel((void *)&e->env[oldpwd]);
	e->env[oldpwd] = join_env("OLDPWD", "=", \
			ft_get_post_env_value(e->env[pwd]));
	ft_memdel((void *)&e->env[pwd]);
	if (args[1])
		dir = ft_strjoin(ft_get_post_env_value(e->env[home]), args[1] + 1);
	else
		dir = ft_get_post_env_value(e->env[home]);
	e->env[pwd] = join_env("PWD", "=", dir);
	if (chdir(dir) != 0)
		display_error(args);
	free(dir);
}

static void		swap_dir(t_env *e, char **args)
{
	char		*tmp_old;
	char		*tmp_current;
	int			pwd;
	int			oldpwd;

	pwd = get_env(e, "PWD");
	oldpwd = get_env(e, "OLDPWD");
	tmp_old = ft_get_post_env_value(e->env[oldpwd]);
	tmp_current = ft_get_post_env_value(e->env[pwd]);
	ft_memdel((void *)&e->env[oldpwd]);
	e->env[oldpwd] = join_env("OLDPWD", "=", tmp_current);
	ft_memdel((void *)&e->env[pwd]);
	e->env[pwd] = join_env("PWD", "=", tmp_old);
	if (chdir(tmp_old) != 0)
		display_error(args);
	free(tmp_old);
	free(tmp_current);
}

static void		basic_dir(t_env *e)
{
	int			pwd;
	int			oldpwd;

	pwd = get_env(e, "PWD");
	oldpwd = get_env(e, "OLDPWD");
	ft_memdel((void *)&e->env[oldpwd]);
	e->env[oldpwd] = join_env("OLDPWD", "=",\
			ft_get_post_env_value(e->env[pwd]));
	ft_memdel((void *)&e->env[pwd]);
	e->env[pwd] = join_env("PWD", "=", getcwd(0, 0));
	return ;
}

void			change_dir(t_env *e, char **args)
{
	check_env(e);
	if ((ft_strcmp(args[0], "cd") == 0 && !args[1]) || args[1][0] == '~')
		tild_dir(e, args);
	else if (chdir(args[1]) == 0)
		basic_dir(e);
	else if (args[1][0] == '-')
		swap_dir(e, args);
	else
		display_error(args);
}
