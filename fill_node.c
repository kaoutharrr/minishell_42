/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:39 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/13 23:53:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_input_redirection(t_cmd **lst, t_vars *vars)
{
	(*lst)->files[vars->i_file].file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 0;
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_output_redirection(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 1;
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_herdoc(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 2;
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_append(t_cmd **lst, t_vars *vars)
{
	(*(lst))->files[vars->i_file].file = ft_strdup(vars->ar_2d[vars->i_2d
			+ 1]);
	(*(lst))->files[vars->i_file].type = 3;
	vars->i_file++;
	vars->i_2d += 2;
}

void	ft_command(t_cmd **lst, t_vars *vars)
{
	(*lst)->command[vars->i_cmd] = ft_strdup(vars->ar_2d[vars->i_2d]);
	vars->i_cmd++;
	vars->i_2d++;
}
