/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:37:30 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/16 02:02:51 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char	*get_env_value(char *str)
{
	char	*variable;
	char	*value;
	t_list	*list;

	list = g_llobal.global;
	variable = ft_strjoin_char(str, '=');
	value = NULL;
	while (list)
	{
		value = ft_str_env_cmp(variable, list->content);
		if (value)
		{
			free(variable);
			return (value);
		}
		free(value);
		list = list->next;
	}
	free(variable);
	value = ft_strdup("");
	return (value);
}

int	redirection_before(t_vars *vars)
{
	if (vars->i_2d < 1)
		return (0);
	if (ft_strcmp(vars->ar_2d[vars->i_2d - 1], ">") == 0)
		return (1);
	if (ft_strcmp(vars->ar_2d[vars->i_2d - 1], ">>") == 0)
		return (1);
	if (ft_strcmp(vars->ar_2d[vars->i_2d - 1], "<<") == 0)
		return (2);
	if (ft_strcmp(vars->ar_2d[vars->i_2d - 1], "<") == 0)
		return (1);
	return (0);
}

char	*expand2(t_vars *vars)
{
	if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\'')
	{
		if (!single_quotes(vars))
			return (NULL);
	}
	else if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\"')
	{
		if (!double_quotes(vars))
			return (NULL);
	}
	else
	{
		if (!no_quotes(vars))
			return (NULL);
	}
	return ("GOOD");
}

char	*expand(t_vars *vars, char *temp, int ok)
{
	vars->i_2d = -1;
	while (vars->ar_2d[++vars->i_2d])
	{
		if (ok == 1 && redirection_before(vars) > 0)
			continue ;
		else if (ok == 2 && redirection_before(vars) == 2)
			continue ;
		vars->str_exp = malloc(1);
		vars->str_exp[0] = '\0';
		vars->i_xp = 0;
		while (vars->ar_2d[vars->i_2d][vars->i_xp])
		{
			if (!expand2(vars))
				return (NULL);
		}
		temp = vars->ar_2d[vars->i_2d];
		vars->ar_2d[vars->i_2d] = vars->str_exp;
		free(temp);
	}
	return (NULL);
}
