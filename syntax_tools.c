/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:17:38 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 01:34:46 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	next_char(t_vars *vars, char *input)
{
	while (input[vars->i_er] && (input[vars->i_er] == 9
			|| input[vars->i_er] == 32))
		vars->i_er++;
	return (input[vars->i_er]);
}

char	*ft1_left(t_vars *vars, char *input, char c)
{
	if (c == '\0')
		return ("syntax error near unexpected token `newline'");
	if (c == '|')
		return ("syntax error near unexpected token `|'");
	if (c == '>')
	{
		if (input[vars->i_er + 1] && input[vars->i_er + 1] == '>')
		{
			if (input[vars->i_er + 2] && input[vars->i_er + 2] == '>')
				return ("syntax error near unexpected token `>>>'");
			return ("syntax error near unexpected token `>>'");
		}
		return ("syntax error near unexpected token `>'");
	}
	if (c == '<')
	{
		if (input[vars->i_er + 1] && input[vars->i_er + 1] == '<')
		{
			if (input[vars->i_er + 2] && input[vars->i_er + 2] == '<')
				return ("syntax error near unexpected token `<<<'");
			return ("syntax error near unexpected token `<<'");
		}
		return ("syntax error near unexpected token `<'");
	}
	return (NULL);
}

char	*check_left_redirection(t_vars *vars, char *input)
{
	int		n;
	char	c;
	char	*res;

	n = 0;
	if (input[vars->i_er + 1] && input[vars->i_er + 1] == '>')
		return ("parse error near `<>'");
	while (input[vars->i_er] && input[vars->i_er] == '<' && n < 5)
	{
		vars->i_er++;
		n++;
	}
	if (n == 3)
		return ("syntax error near unexpected token `<'");
	if (n > 3)
		return ("syntax error near unexpected token `<<'");
	if (n <= 2)
	{
		c = next_char(vars, input);
		res = ft1_left(vars, input, c);
		if (res)
			return (res);
	}
	return (NULL);
}

char	*single_dollar(t_vars *vars)
{
	char	*temp;

	if (vars->ar_2d[vars->i_2d][vars->i_xp] == '?')
	{
		exit_status(vars);
		return ("GOOD");
	}
	if (vars->ar_2d[vars->i_2d][vars->i_xp] == '\0'
		|| special_char(vars->ar_2d[vars->i_2d][vars->i_xp]) == 0)
	{
		temp = vars->str_exp;
		vars->str_exp = ft_strjoin_char(vars->str_exp, '$');
		if (!vars->str_exp)
			return (NULL);
		free(temp);
		return ("Skip");
	}
	else if (special_char(vars->ar_2d[vars->i_2d][vars->i_xp]) == 2)
	{
		vars->i_xp++;
		return ("Good");
	}
	else
		return ("Continue");
}

char	*detect_variable(t_vars *vars, char *variable, char *value, char *temp)
{
	int		i;
	char	*res;

	vars->i_xp++;
	i = vars->i_xp;
	res = single_dollar(vars);
	if (ft_strcmp(res, "Continue") == 0)
	{
		while (vars->ar_2d[vars->i_2d][vars->i_xp]
			&& special_char(vars->ar_2d[vars->i_2d][vars->i_xp]) != 0)
			vars->i_xp++;
		variable = ft_substr(vars->ar_2d[vars->i_2d], i, vars->i_xp - i);
		value = get_env_value(variable);
		if (value)
		{
			temp = vars->str_exp;
			vars->str_exp = ft_strjoin(vars->str_exp, value);
			free(temp);
		}
		free(variable);
		free(value);
		return ("Good");
	}
	else
		return (res);
}
