/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:04:33 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/15 00:00:06 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_2d(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->ar_2d[i])
	{
		free(vars->ar_2d[i]);
		i++;
	}
	free(vars->ar_2d);
	vars->ar_2d = NULL;
}

char	*clear_expand(t_vars *vars)
{
	char	**res;

	res = clear_expand2(vars);
	if (!res)
	{
		free_2d(vars);
		return (NULL);
	}
	vars->i_2d = 0;
	if (split_2dar(vars, 0, 0, 0))
		return ("GOOD");
	else
		return (NULL);
}
