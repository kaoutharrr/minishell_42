/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:02:47 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 05:24:30 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	cd_process(char **command)
{
	char	*dir;
	char	*current;

	current = getcwd(NULL, 0);
	if (!current && (command[1] && (ft_strcmp(command[1], ".")
				|| ft_strcmp(command[1], ".."))))
		return (error_cd("cd :", "cwd:cannot access parent directories\n", 1));
	if (!command[1] || !ft_strcmp(command[1], "~"))
	{
		dir = ft_strdup(get_env("HOME"));
		if (!dir)
			return (free(current), error_cd("cd :", "HOME NOT SET\n`", 1));
		chdir(dir);
	}
	else
		dir = cd1(command[1]);
	if (current && (dir || command[1]))
		ft_update(getcwd(NULL, 0), current);
	free(dir);
	free(current);
	g_llobal.status = 0;
	return (0);
}

int	error_cd(char *s1, char *s2, int status)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	g_llobal.status = status;
	return (1);
}

char	*cd1(char *command)
{
	char	*dir;

	dir = ft_strdup(command);
	if (chdir(dir) == -1)
	{
		if (ft_strcmp(command, "\0"))
			perror(dir);
		g_llobal.status = 1;
		return (free(dir), NULL);
	}
	free(dir);
	dir = getcwd(NULL, 0);
	if (!dir)
	{
		ft_putstr_fd("HOME NOT SET\n", 2);
		return (NULL);
	}
	return (dir);
}

void	ft_update(char *dir, char *current)
{
	char	*s;
	t_list	*global;

	s = NULL;
	global = g_llobal.global;
	while (global)
	{
		if (!ft_strncmp(global->content, "PWD", 3))
		{
			s = global->content;
			global->content = ft_strjoin("PWD=", dir);
			free(s);
		}
		else if (!ft_strncmp(global->content, "OLDPWD", 6))
		{
			s = global->content;
			global->content = ft_strjoin("OLDPWD=", current);
			free(s);
		}
		global = global->next;
	}
	free(dir);
}
