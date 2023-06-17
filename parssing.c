/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:02:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 04:06:58 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

void	ft_free_2d_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	if (str)
		free(str);
	str = NULL;
}

void	ft_free_lst(t_cmd **lst)
{
	int		i;
	t_cmd	*temp;

	while ((*lst))
	{
		i = 0;
		ft_free_2d_array((*lst)->command);
		if ((*lst)->files && (*lst)->files[i].file)
		{
			while ((*lst)->files[i].file)
			{
				if ((*lst)->files[i].file)
					free((*lst)->files[i].file);
				i++;
			}
		}
		free((*lst)->files);
		(*lst)->files = NULL;
		temp = (*lst);
		(*lst) = (*lst)->next;
		free(temp);
	}
}

void	ft_free_allocation(t_cmd **lst, t_vars *vars, char *input)
{
	if ((*lst))
		ft_free_lst(lst);
	if (vars->ar_2d)
		ft_free_2d_array(vars->ar_2d);
	if (input)
		free(input);
	input = NULL;
	if (vars->mask)
		free(vars->mask);
}

char	*parssing(t_cmd **lst, t_vars *vars, char *input)
{
	char	*error;
	int		i;

	error = NULL;
	if (!create_2d_array(vars, input))
		return (NULL);
	i = 0;
	vars->i_2d = -1;
	expand(vars, NULL, 1);
	if (!clear_expand(vars))
		return (NULL);
	expand(vars, NULL, 2);
	if (!create_list(lst, vars))
		return (NULL);
	clear_list(lst, vars);
	return ("Good");
}

char	*empty_cmd(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] <= 32)
		i++;
	if (!input[i])
		return (NULL);
	return (input);
}
