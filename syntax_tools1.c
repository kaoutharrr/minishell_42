/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:23:39 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/09 22:23:40 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft1_right(t_vars *vars, char *input, char c, int n)
{
	if (c == '\0')
		return ("syntax error near unexpected token `newline'");
	if (c == '|' && n == 2)
		return ("syntax error near unexpected token `|'");
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
	return (NULL);
}

char	*ft00_right(t_vars *vars, char *input)
{
	if (input[vars->i_er + 3] && input[vars->i_er + 3] == '<')
	{
		if (input[vars->i_er + 4] && input[vars->i_er + 4] == '<')
			return ("syntax error near unexpected token `<<<'");
		return ("syntax error near unexpected token `<<'");
	}
	return ("syntax error near unexpected token `<'");
}

char	*ft0_right(t_vars *vars, char *input)
{
	if (input[vars->i_er + 1] && input[vars->i_er + 1] == '|')
	{
		if (input[vars->i_er + 2] && input[vars->i_er + 2] == '>')
		{
			if (input[vars->i_er + 3] && input[vars->i_er + 3] == '|')
				return ("syntax error near unexpected token `>|'");
			if (input[vars->i_er + 3] && input[vars->i_er + 3] == '>')
			{
				if (input[vars->i_er + 4] && input[vars->i_er + 4] == '>')
					return ("syntax error near unexpected token `>>'");
				return ("syntax error near unexpected token `>'");
			}
		}
		if (input[vars->i_er + 2] && input[vars->i_er + 2] == '<')
			return (ft00_right(vars, input));
		vars->i_er += 2;
	}
	return (NULL);
}

char	*ft2_right(t_vars *vars, char *input, int n)
{
	char	*res;
	char	c;

	c = next_char(vars, input);
	if (n == 1 && c == '|' && (input[vars->i_er - 1] >= 9 && input[vars->i_er
				- 1] <= 32))
		return ("syntax error near unexpected token `|'");
	res = ft1_right(vars, input, c, n);
	if (res)
		return (res);
	return (NULL);
}

char	*check_right_redirection(t_vars *vars, char *input)
{
	int		n;
	char	*res;

	n = 0;
	res = ft0_right(vars, input);
	if (res)
		return (res);
	while (input[vars->i_er] && input[vars->i_er] == '>' && n < 5)
	{
		vars->i_er++;
		n++;
	}
	if (n == 3)
		return ("syntax error near unexpected token `>'");
	if (n > 3)
		return ("syntax error near unexpected token `>>'");
	if (n <= 2)
	{
		res = ft2_right(vars, input, n);
		return (res);
	}
	return (NULL);
}
