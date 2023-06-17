/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:55:04 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 01:36:22 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rm_quotes2(t_cmd **lst, t_vars *vars, char *temp, char c)
{
	while ((*lst)->command[vars->i_2d][++vars->i_cmd])
	{
		if ((*lst)->command[vars->i_2d][vars->i_cmd] != '"'
			&& (*lst)->command[vars->i_2d][vars->i_cmd] != '\'')
		{
			temp = vars->str_quotes;
			vars->str_quotes = ft_strjoin_char(vars->str_quotes,
					(*lst)->command[vars->i_2d][vars->i_cmd]);
			free(temp);
		}
		else
		{
			c = (*lst)->command[vars->i_2d][vars->i_cmd++];
			while ((*lst)->command[vars->i_2d][vars->i_cmd]
				&& (*lst)->command[vars->i_2d][vars->i_cmd] != c)
			{
				temp = vars->str_quotes;
				vars->str_quotes = ft_strjoin_char(vars->str_quotes,
						(*lst)->command[vars->i_2d][vars->i_cmd++]);
				free(temp);
			}
		}
	}
}

void	clear_list(t_cmd **lst, t_vars *vars)
{
	char	*temp;

	vars->i_2d = 0;
	if ((*lst)->command)
	{
		while ((*lst)->command[vars->i_2d])
		{
			vars->i_cmd = -1;
			vars->str_quotes = malloc(1);
			vars->str_quotes[0] = '\0';
			temp = (*lst)->command[vars->i_2d];
			rm_quotes2(lst, vars, temp, '\'');
			(*lst)->command[vars->i_2d] = vars->str_quotes;
			free(temp);
			vars->i_2d++;
		}
	}
}

char	*exit_status(t_vars *vars)
{
	int		res;
	char	*temp;
	char	*num;

	temp = vars->str_exp;
	res = g_llobal.status;
	num = ft_itoa(res);
	vars->str_exp = ft_strjoin(vars->str_exp, num);
	free(temp);
	free(num);
	vars->i_xp++;
	return ("GOOD");
}
