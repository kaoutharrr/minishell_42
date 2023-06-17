/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:58:56 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 00:49:54 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_builtin(char **cmd)
{
	if (!ft_strcmp(cmd[0], "echo") || !ft_strcmp(cmd[0], "cd")
		||!ft_strcmp(cmd[0], "export")
		||!ft_strcmp(cmd[0], "unset")
		||!ft_strcmp(cmd[0], "env")
		||!ft_strcmp(cmd[0], "pwd")
		||!ft_strcmp(cmd[0], "exit"))
		return (1);
	else
		return (0);
}

void	builtins(char **command, int fd)
{
	if (!ft_strcmp(command[0], "echo"))
		echo_process(command, fd);
	if (!ft_strcmp(command[0], "cd"))
		cd_process(command);
	if (!ft_strcmp(command[0], "pwd"))
		pwd_process(fd);
	if (!ft_strcmp(command[0], "export"))
		export_process(command, fd);
	if (!ft_strcmp(command[0], "unset"))
		unset_process(command);
	if (!ft_strcmp(command[0], "env"))
		env_process(command, fd);
	if (!ft_strcmp(command[0], "exit"))
		exit_process(command);
}

void	builtins_child(char **command, int fd)
{
	if (!ft_strcmp(command[0], "echo"))
		echo_process(command, fd);
	if (!ft_strcmp(command[0], "cd"))
		cd_process(command);
	if (!ft_strcmp(command[0], "pwd"))
		pwd_process(fd);
	if (!ft_strcmp(command[0], "export"))
		export_process(command, fd);
	if (!ft_strcmp(command[0], "unset"))
		unset_process(command);
	if (!ft_strcmp(command[0], "env"))
		env_process(command, fd);
	if (!ft_strcmp(command[0], "exit"))
		exit_child_process(command);
}

int	ft_check_n(char *command)
{
	int	i;

	i = 1;
	while (command[i])
	{
		if (command[i] == 'n')
			i++;
		else
			return (1);
	}
	return (0);
}
