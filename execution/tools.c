/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:14:05 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 05:35:02 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	protection(char **command, char **arr)
{
	if (access(command[0], X_OK) == 0)
		execve(command[0], command, arr);
	else
		not_found(command[0], ": no such file or directory", 127);
}

char	**find_path(char **arr)
{
	char	**mypath;
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strnstr(arr[i], "PATH=", 5))
		{
			mypath = ft_split(arr[i] + 5, ':');
			return (mypath);
		}
		i++;
	}
	return (NULL);
}

void	ft_check(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[0] == '-' || cmd[0] == '+')
		i++;
	while (cmd[i])
	{
		if (cmd[i] <= '9' && cmd[i] >= '0')
			i++;
		else
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
	}
}

void	print_command(char **command, int fd)
{
	int	i;

	i = 1;
	while (command[i])
	{
		ft_putstr_fd(command[i], fd);
		ft_putstr_fd(" ", fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	fill_end(t_cmd *cmd, int **end)
{
	int	i;
	int	a;

	a = 0;
	while (cmd)
	{
		i = 0;
		while (cmd->files[i].type != -1)
		{
			if (cmd->files[i].type == 2)
			{	
				cmd->files[i].fd = end[a][0];
				a++;
			}
			i++;
		}
		cmd = cmd->next;
	}
}
