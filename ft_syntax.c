/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:46:23 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/14 00:54:10 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_quotes(t_vars *vars, char *str, char c)
{
	++vars->i_er;
	if (str[vars->i_er] == '\0')
		return (0);
	while (str[vars->i_er] && str[vars->i_er] != c)
		vars->i_er++;
	if (str[vars->i_er] == '\0')
		return (0);
	else
	{
		vars->i_er++;
		return (1);
	}
}

int	check_pipe(t_vars *vars, char *input)
{
	int		i;
	char	c;

	c = next_char(vars, input);
	if (vars->i_er == 0 || vars->i_er == (int)ft_strlen(input))
		return (0);
	else if (input[vars->i_er + 1] == '|' || input[vars->i_er + 1] == '\0')
		return (0);
	i = ++vars->i_er;
	while (input[i] && ((input[i] >= 9 && input[i] <= 13) || input[i] == 32))
		i++;
	if (input[i] == '\0' || input[i] == '|')
		return (0);
	return (1);
}

char	*syntax_redirection(char *input, t_vars *vars)
{
	char	*str;

	str = NULL;
	if (input[vars->i_er] == '>')
	{
		str = check_right_redirection(vars, input);
		if (str)
			return (str);
	}
	else if (input[vars->i_er] == '<')
	{
		str = check_left_redirection(vars, input);
		if (str)
			return (str);
	}
	return (str);
}

char	*ft_synstax_red(char *input, t_vars *vars)
{
	char	*str;

	if (input[vars->i_er] == '|')
	{
		if (check_pipe(vars, input) == 0)
			return ("syntax error near unexpected token `|'");
	}
	if (input[vars->i_er] == '>')
	{
		str = check_right_redirection(vars, input);
		if (str)
			return (str);
	}
	else if (input[vars->i_er] == '<')
	{
		str = check_left_redirection(vars, input);
		if (str)
			return (str);
	}
	return (NULL);
}

int	ft_synstax(char *input, t_vars *vars)
{
	char	*str;

	str = NULL;
	vars->i_er = 0;
	while (input[vars->i_er])
	{
		if (input[vars->i_er] == '\'' || input[vars->i_er] == '"')
		{
			if (check_quotes(vars, input, input[vars->i_er]) == 0)
				return (ft_error(input, "syntax error near unexpected quote",
						258));
		}
		else if (input[vars->i_er] == '|' || input[vars->i_er] == '>'
			|| input[vars->i_er] == '<')
		{
			str = ft_synstax_red(input, vars);
			if (str)
				return (ft_error(input, str, 258));
		}
		else
			vars->i_er++;
	}
	return (0);
}
