/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:19:18 by clesaffr          #+#    #+#             */
/*   Updated: 2023/01/02 19:49:23 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_MINISHELL_H
# define INC_MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft/libft.h"

typedef	struct s_command_line
{
	char	*command;
	int		fd;
	int		env;
}				t_command_line;

#endif
