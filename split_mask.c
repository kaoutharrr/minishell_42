/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:00:50 by adadoun           #+#    #+#             */
/*   Updated: 2023/04/30 19:01:00 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_mask_quotes(t_vars *vars, char *str, int i)
{
	char	c;

	c = str[i];
	vars->mask[i++] = '1';
	while (str[i] && str[i] != c)
		vars->mask[i++] = '1';
	vars->mask[i] = '1';
	return (i);
}

char	*create_mask(t_vars *vars, char *str, int i)
{
	vars->mask = malloc((sizeof(char) + 1) * ft_strlen(str));
	if (!vars->mask)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			vars->mask[i] = '0';
		else if (str[i] == '|' && i > 0 && str[i - 1] == '>')
			vars->mask[i] = '0';
		else if (str[i] == '|')
			vars->mask[i] = '3';
		else if (str[i] == '<')
			vars->mask[i] = '2';
		else if (str[i] == '>')
			vars->mask[i] = '9';
		else if (str[i] == '"' || str[i] == '\'')
			i = create_mask_quotes(vars, str, i);
		else
			vars->mask[i] = '1';
	}
	vars->mask[i] = '\0';
	return ("Good");
}

int	n_word(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->word = 0;
	while (vars->mask[i])
	{
		j = 0;
		while (vars->mask[i + j] && vars->mask[i + j] != '0'
			&& vars->mask[i] == vars->mask[i + j])
			j++;
		if (j != 0)
		{
			vars->word++;
			i += j;
		}
		else
			i++;
	}
	return (vars->word);
}

char	*split_mask(t_vars *vars, char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	vars->ar_2d = malloc((sizeof(char *)) * (n_word(vars) + 1));
	while (vars->mask[i])
	{
		j = 0;
		while (vars->mask[i + j] && vars->mask[i + j] != '0'
			&& vars->mask[i] == vars->mask[i + j])
			j++;
		if (j != 0)
		{
			vars->ar_2d[x] = ft_substr(str, i, j);
			i += j;
			x++;
		}
		else
			i++;
	}
	vars->ar_2d[x] = NULL;
	return ("Good");
}

char	*create_2d_array(t_vars *vars, char *str)
{
	if (!create_mask(vars, str, -1))
		return (NULL);
	if (!split_mask(vars, str))
		return (NULL);
	if (vars->mask)
		free(vars->mask);
	vars->mask = NULL;
	return ("Good");
}
