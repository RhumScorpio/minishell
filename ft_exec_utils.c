/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:21:25 by alewalla          #+#    #+#             */
/*   Updated: 2023/02/27 16:30:47 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_last_pid(t_exec *exec)
{
	t_exec	*tmp;

	tmp = exec;
	while (tmp->next_link)
		tmp = tmp->next_link;
	return (tmp->pid);
}

t_exec	*ft_get_first_exec(t_exec *exec)
{
	t_exec	*tmp;

	tmp = exec;
	while (tmp->previous_link)
		tmp = tmp->previous_link;
	return (tmp);
}

void	ft_set_redirection(t_exec *exec, t_tok *tmp)
{
	if (tmp->type == OUTFILE)
		exec->outfile = ft_open_redirection(tmp->data, OUTFILE);
	if (tmp->type == APPEND)
		exec->append = ft_open_redirection(tmp->data, APPEND);
	if (tmp->type == HEREDOC)
		exec->heredoc = ft_heredoc(tmp->data);
}

int	ft_handle_empty_arg(t_env *envl)
{
	free(envl->value);
	envl->value = ft_strdup("0");
	return (0);
}
