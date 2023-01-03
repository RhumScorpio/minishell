/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:01:09 by clesaffr          #+#    #+#             */
/*   Updated: 2023/01/03 20:17:57 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_MINISHELL_H
# define INC_MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command_line	t_command_line;

typedef	struct s_command_line
{
	char		*command;
	t_command_line	*next;
}				t_command_line;

#endif
