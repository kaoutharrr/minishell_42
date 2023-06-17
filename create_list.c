/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:28 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/14 17:56:43 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_arguments(t_args *args, t_vars *vars)
{
	args->cmd_index = 1;
	vars->i_2d = 0;
}

void	fill_cmd(t_cmd **lst, t_args *args, t_vars *vars)
{
	vars->i_file = 0;
	vars->i_cmd = 0;
	(*lst)->index = args->cmd_index++;
	while (vars->ar_2d[vars->i_2d] && vars->ar_2d[vars->i_2d][0] != '|')
	{
		if (vars->ar_2d[vars->i_2d][0] && ft_strcmp(vars->ar_2d[vars->i_2d],
				"<") == 0)
			ft_input_redirection(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], ">") == 0)
			ft_output_redirection(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], "<<") == 0)
			ft_herdoc(lst, vars);
		else if (vars->ar_2d[vars->i_2d][0]
				&& ft_strcmp(vars->ar_2d[vars->i_2d], ">>") == 0)
			ft_append(lst, vars);
		else
			ft_command(lst, vars);
	}
	(*lst)->command[vars->i_cmd] = NULL;
	(*lst)->files[vars->i_file].file = NULL;
	(*lst)->files[vars->i_file].type = -1;
}

void	if_pipe_at_end(t_cmd **temp1, t_vars *vars)
{
	if (!vars->ar_2d[vars->i_2d] && vars->ar_2d[vars->i_2d - 1][0] == '|')
	{
		(*temp1)->command = NULL;
		(*temp1)->files = NULL;
		(*temp1)->next = NULL;
	}
}

char	*fill_lst(t_cmd **lst, t_args *args, t_vars *vars)
{
	t_cmd	*temp1;

	vars->i_2d = 0;
	(*lst) = ft_lstnew_1(0);
	if (!(*lst))
		return (NULL);
	temp1 = (*lst);
	while (vars->ar_2d[vars->i_2d])
	{
		alloc_cmd(&temp1, vars);
		alloc_files(&temp1, vars);
		temp1->command[0] = NULL;
		temp1->files[0].file = NULL;
		temp1->files[0].type = 0;
		fill_cmd(&temp1, args, vars);
		if (!vars->ar_2d[vars->i_2d])
			break ;
		vars->i_2d++;
		temp1->next = ft_lstnew_1(0);
		temp1 = temp1->next;
		if_pipe_at_end(&temp1, vars);
	}
	return ("Good");
}

char	*create_list(t_cmd **lst, t_vars *vars)
{
	t_args	args;

	init_arguments(&args, vars);
	if (!fill_lst(lst, &args, vars))
		return (NULL);
	return ("Good");
}
