/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:22:50 by clesaffr          #+#    #+#             */
/*   Updated: 2023/01/03 20:24:54 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_cmd(int sig)
{
	if (sig == SIGQUIT)
		exit (1);
}

void	free_all(t_command_line *first)
{
	t_command_line	*tmp;

	tmp = first;
	while (tmp->next)
	{
		free(tmp->command);
		tmp = tmp->next;
	}
	free(tmp->command);
}

void	command_line(char *cmd, t_command_line *first)
{
	t_command_line	*tmp;

	tmp = first;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->command = cmd;
	tmp->next = NULL;
}

int	main(int ac, char **av)
{
	static t_command_line	*first;	
	char			*cmd;

	(void)ac;
	(void)av;
	first->command = readline("minishell$> ");
	first->next = NULL;
	while (1)
	{
		cmd = readline("minishell$> ");
		add_history(cmd);
		printf("cmd = %s\n", cmd);
		command_line(cmd, first);
		if (ft_strcmp(cmd, "exit"))
		{
			free(cmd);
			free_all(first);
			exit (1);
		}
		signal(SIGINT, signal_cmd);
		signal(SIGQUIT, SIG_IGN);
	}
}
