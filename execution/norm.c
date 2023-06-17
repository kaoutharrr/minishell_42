/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:21:03 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 05:33:34 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_execute(t_cmd *cmd, char **arr)
{
	char	**paths;
	int		i;

	i = 0;
	protections(cmd->command, arr);
	paths = find_path(arr);
	if (!paths)
	{
		if (access(cmd->command[0], X_OK) == 0)
			execve(cmd->command[0], cmd->command, arr);
	}
	execute_cmd(paths, cmd->command, arr);
	myfree(arr);
	myfree(paths);
	not_found(cmd->command[0], " : command not found ", 127);
	myfree(cmd->command);
	exit(127);
}

void	protections(char **command, char **arr)
{
	if (!command)
		not_found("command not found: ", " ", 127);
	if (command[0][0] == '\0')
		not_found("command not found: ", command[0], 127);
	if (command[0][0] == '/' || !ft_strncmp(command[0], "./", 2))
		protection(command, arr);
	if (! ft_strcmp(command[0], "."))
		not_found(command[0], " : filename argument required\n", 2);
}

void	execute_cmd(char **paths, char **command, char **arr)
{
	char	*joined;
	char	*path;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		joined = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(joined, command[0]);
		if (is_builtin(command) == 1)
		{
			builtins_child(command, 1);
			exit(0);
		}
		else if (access(path, F_OK) == 0 || access(path, X_OK) == 0)
		{
			if (execve(path, command, arr) == -1)
				exit(1);
		}
		free(path);
		free(joined);
	}
}

int	should_expand(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '"' || name[i] == '\'')
			return (-1);
		i++;
	}
	return (0);
}
