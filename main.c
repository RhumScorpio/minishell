/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:22:50 by clesaffr          #+#    #+#             */
/*   Updated: 2023/01/02 20:39:05 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_minishell.h"

void	signal_cmd(int sig)
{
	if (sig == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		exit (1);
	}
}

int	main(int ac, int **av)
{
	char			*cmd;

	while (1)
	{
		cmd = readline("minishell$> ");
		printf("cmd = %s\n", cmd);
		if (ft_strcmp(cmd, "exit"))
			exit (1);
		signal(SIGINT, signal_cmd);
		signal(SIGQUIT, SIG_IGN);
		free(cmd);
	}
}
