/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:49:05 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:49:32 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int		split_builtin_exit(char **name, int i)
{
	while (name[1][++i])
	{
		if (ft_isdigit((int)name[1][i]) == 0)
		{
			ft_putstr("exit: Expression syntax.\n");
			return (1);
		}
	}
	return (0);
}

void	exit_shell(t_env *e, char **name)
{
	int		nbr;
	int		i;
	int		fd;

	(void)e;
	fd = open("/dev/tty", O_RDWR);
	if (name[1])
	{
		if (!name[2])
		{
			i = -1;
			if (split_builtin_exit(name, i) == 1)
				return ;
			nbr = ft_atoi(name[1]);
			if (nbr > 255)
				nbr = 0;
			ft_putendl("\033[31mexiting minishell1...\033[0m");
			exit(nbr);
		}
		ft_putstr("exit: Expression syntax.\n");
		return ;
	}
	ft_putendl("\033[31mexiting minishell1...\033[0m");
	exit(0);
}
