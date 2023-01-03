/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:22:50 by clesaffr          #+#    #+#             */
/*   Updated: 2023/01/03 15:02:48 by clesaffr         ###   ########.fr       */
/*                                                                            */
#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef	struct s_command_line
{
	char	*command;
	int		fd;
	int		env;
}				t_command_line;

#endif
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

void	signal_cmd(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		exit (1);
	}
}

int	main(int ac, char **av)
{
	char			*cmd;

	(void)ac;
	(void)av;
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
