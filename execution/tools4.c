/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:28:56 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 04:07:21 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_flag(int flag, char *command)
{
	if (flag == 1)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(" : not a valid identifier\n", 2);
		g_llobal.status = 1;
	}
}

char	*rm_quotes(char *input, int i, char *str, char *temp)
{
	char	c;

	str = malloc(1);
	str[0] = '\0';
	while (input[++i])
	{
		if (input[i] != '"' && input[i] != '\'')
		{
			temp = str;
			str = ft_strjoin_char(str, input[i]);
			free(temp);
		}
		else
		{
			c = input[i];
			while (input[i] && input[i] != c)
			{
				temp = str;
				str = ft_strjoin_char(str, input[i++]);
				free(temp);
			}
		}
	}
	return (str);
}

int	exit_child_process(char **command)
{
	int	nbr;

	if (command[1])
		ft_check(command[1]);
	if (command[1] && command[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (0);
	}
	if (!command[1])
		exit(g_llobal.status);
	nbr = ft_atoi(command[1]);
	exit(nbr);
}

int	ft_lst_size(t_cmd *lst)
{
	int	list_size;

	list_size = 0;
	while (lst)
	{
		list_size++;
		lst = lst->next;
	}
	return (list_size);
}
