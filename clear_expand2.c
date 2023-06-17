/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_expand2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:04:33 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/15 00:21:05 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	calculate_cmd_nopipe(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->ar_2d[i])
	{
		if (vars->ar_2d[i][0] != '|' && vars->ar_2d[i][0] != '\0')
			n++;
		i++;
	}
	return (n);
}

int	calculate_cmd(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->ar_2d[i])
	{
		if (vars->ar_2d[i][0] != '\0')
			n++;
		i++;
	}
	return (n);
}

char	**clear_expand2(t_vars *vars)
{
	int		i;
	int		j;
	char	**new_2d;

	i = 0;
	j = 0;
	if (calculate_cmd_nopipe(vars) == 0)
		return (NULL);
	new_2d = malloc(sizeof(char *) * (calculate_cmd(vars) + 1));
	i = -1;
	while (vars->ar_2d[++i])
	{
		if (vars->ar_2d[i][0] && vars->ar_2d[i][0] != '\0')
		{
			new_2d[j] = ft_strdup(vars->ar_2d[i]);
			j++;
		}
	}
	new_2d[j] = NULL;
	free_2d(vars);
	vars->ar_2d = new_2d;
	return (new_2d);
}
