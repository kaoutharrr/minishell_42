/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:54:09 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 17:11:24 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	echo1(char **command, int fd)
{
	int	i;
	int	flag;

	i = 1;
	while (command[i])
	{
		while (!ft_strncmp(command[i], "-n", 2))
		{
			flag = ft_check_n(command[i]);
			if (!flag)
			{
				i++;
				if (!command[i])
					break ;
			}
			else
				break ;
		}
		while (command[i])
		{
			ft_putstr_fd(command[i++], fd);
			ft_putchar_fd(' ', fd);
		}
	}
	return (0);
}

void	unset1(char **arr, char *command)
{
	int		j;
	char	**split;

	j = 0;
	while (arr[j])
	{
		split = ft_split(arr[j], '=');
		if (!ft_strcmp(split[0], command))
			remove_list(&g_llobal.global, arr[j]);
		myfree(split);
		j++;
	}
}

void	check_env(t_list *tmp, int fd)
{
	int	i;

	i = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{	
			if (tmp->content[i] == '=')
			{
				ft_putstr_fd(tmp->content, fd);
				ft_putchar_fd('\n', fd);
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}
