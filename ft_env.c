/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:32:44 by alewalla          #+#    #+#             */
/*   Updated: 2023/02/27 19:57:39 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_putstr(envp[i]);
		ft_putchar('\n');
	}
}
