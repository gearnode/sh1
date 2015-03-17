/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:38:48 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 13:05:53 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int				args_is_valid(char *arg)
{
	size_t		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg[len] != 0 && arg[len] != '=')
		len++;
	if (len != ft_strlen(arg))
		return (1);
	return (0);
}


int			arg_to_display(char *arg)
{
	size_t		len;

	if (!arg)
		return (0);
	len = 0;
	while (arg[len] != 0 && arg[len] != '=')
		len++;
	if (arg[len] == '=')
		return (1);
	return (0);
}

int			check_all_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (args_is_valid(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
