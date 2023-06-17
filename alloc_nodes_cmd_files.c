/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_nodes_cmd_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:15 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/13 23:53:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	alloc_cmd(t_cmd **lst, t_vars *vars)
{
	int	i;
	int	n_cmd;

	i = vars->i_2d;
	n_cmd = 0;
	while (vars->ar_2d[i] && vars->ar_2d[i][0] != '|')
	{
		if (vars->ar_2d[i][0] == '>' || vars->ar_2d[i][0] == '<')
			i += 2;
		else
		{
			n_cmd++;
			i++;
		}
	}
	(*lst)->command = malloc(sizeof(char *) * (n_cmd + 1));
	if (!((*lst)->command))
		exit(1);
	(*lst)->command[0] = NULL;
}

void	alloc_files(t_cmd **lst, t_vars *vars)
{
	int	i;
	int	n_files;

	i = vars->i_2d;
	n_files = 0;
	while (vars->ar_2d[i] && vars->ar_2d[i][0] != '|')
	{
		if (vars->ar_2d[i][0] == '>' || vars->ar_2d[i][0] == '<')
		{
			n_files++;
			i += 2;
		}
		else
			i++;
	}
	(*lst)->files = malloc(sizeof(t_files) * (n_files + 1));
	if (!((*lst)->files))
		exit(1);
	(*lst)->files->file = NULL;
}
