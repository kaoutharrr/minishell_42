/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:57:54 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/14 18:01:16 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*no_quotes(t_vars *vars)
{
	char	*temp;

	while (vars->ar_2d[vars->i_2d][vars->i_xp]
		&& vars->ar_2d[vars->i_2d][vars->i_xp] != '\''
		&& vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '|')
			g_llobal.status = 0;
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
		{
			vars->no_quotes = 1;
			detect_variable(vars, NULL, NULL, NULL);
		}
		else
		{
			temp = vars->str_exp;
			vars->str_exp = ft_strjoin_char(vars->str_exp,
					vars->ar_2d[vars->i_2d][vars->i_xp]);
			vars->i_xp++;
			free(temp);
		}
	}
	return ("Good");
}

char	*double_quotes2(t_vars *vars, char *temp)
{
	while (vars->ar_2d[vars->i_2d][vars->i_xp]
		&& vars->ar_2d[vars->i_2d][vars->i_xp] != '"')
	{
		if (vars->ar_2d[vars->i_2d][vars->i_xp] == '$')
		{
			if (!detect_variable(vars, NULL, NULL, NULL))
				return (NULL);
		}
		else
		{
			temp = vars->str_exp;
			vars->str_exp = ft_strjoin_char(vars->str_exp,
					vars->ar_2d[vars->i_2d][vars->i_xp]);
			if (!vars->str_exp)
			{
				free(temp);
				return (NULL);
			}
			vars->i_xp++;
			free(temp);
		}
	}
	return ("GOOD");
}

char	*double_quotes(t_vars *vars)
{
	char	*temp;

	vars->no_quotes = 0;
	temp = vars->str_exp;
	vars->str_exp = ft_strjoin_char(vars->str_exp,
			vars->ar_2d[vars->i_2d][vars->i_xp]);
	vars->i_xp++;
	free(temp);
	if (!double_quotes2(vars, NULL))
		return (NULL);
	temp = vars->str_exp;
	vars->str_exp = ft_strjoin_char(vars->str_exp,
			vars->ar_2d[vars->i_2d][vars->i_xp]);
	vars->i_xp++;
	free(temp);
	return ("GOOD");
}

char	*single_quotes2(t_vars *vars, char *temp)
{
	while (vars->ar_2d[vars->i_2d][vars->i_xp]
		&& vars->ar_2d[vars->i_2d][vars->i_xp] != '\'')
	{
		temp = vars->str_exp;
		vars->str_exp = ft_strjoin_char(vars->str_exp,
				vars->ar_2d[vars->i_2d][vars->i_xp]);
		if (!vars->str_exp)
		{
			return (NULL);
			free(temp);
		}
		vars->i_xp++;
		free(temp);
	}
	return ("GOOD");
}

char	*single_quotes(t_vars *vars)
{
	char	*temp;

	vars->no_quotes = 0;
	temp = vars->str_exp;
	vars->str_exp = ft_strjoin_char(vars->str_exp,
			vars->ar_2d[vars->i_2d][vars->i_xp]);
	vars->i_xp++;
	free(temp);
	if (!single_quotes2(vars, NULL))
		return (NULL);
	temp = vars->str_exp;
	vars->str_exp = ft_strjoin_char(vars->str_exp,
			vars->ar_2d[vars->i_2d][vars->i_xp]);
	vars->i_xp++;
	free(temp);
	return ("GOOD");
}
