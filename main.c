/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 18:24:01 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 13:05:23 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int			main(void)
{
	t_env			*e;
	extern char		**environ;

	if (!(e = (t_env *)malloc(sizeof(t_env) * 1)))
		exit(-1);
	save_env(environ, e);
	ft_listen_sfd(e);
	free(e);
	return (0);
}
