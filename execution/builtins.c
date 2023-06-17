/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:40:22 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 01:43:11 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	exit_process(char **command)
{
	int	nbr;

	if (command[1])
		ft_check(command[1]);
	if (command[1] && command[2])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_llobal.status = 0;
		return (0);
	}
	if (!command[1])
	{
		printf("exit\n");
		exit(g_llobal.status);
	}
	nbr = ft_atoi(command[1]);
	printf("exit\n");
	exit(nbr);
}

int	unset_process(char **command)
{
	int		i;
	char	**arr;
	int		a;
	int		j;

	j = 0;
	a = 0;
	arr = fill_arr();
	i = 0;
	while (command[i])
	{
		a = ft_parse(command[i]);
		if (a == 1)
		{
			ft_putstr_fd(command[i], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
		}
		unset1(arr, command[i]);
		i++;
	}
	myfree(arr);
	g_llobal.status = 0;
	return (0);
}

int	env_process(char **command, int fd)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = g_llobal.global;
	if (command[1])
	{
		ft_putstr_fd("env : ", 2);
		ft_putstr_fd(command[1], 2);
		ft_putstr_fd(": no such file or directory \n", 2);
		g_llobal.status = 127;
		exit(127);
	}
	check_env(tmp, fd);
	g_llobal.status = 0;
	return (0);
}

int	echo_process(char **command, int fd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	if (!command[1])
		ft_putchar_fd('\n', fd);
	else if (ft_strncmp(command[i], "-n", 2))
		print_command(command, fd);
	else if (!ft_strncmp(command[i], "-n", 2) && ft_check_n(command[i]))
		print_command(command, fd);
	else
		echo1(command, fd);
	g_llobal.status = 0;
	return (0);
}

int	pwd_process(int fd)
{
	char	dir[PATH_MAX];

	getcwd(dir, PATH_MAX);
	ft_putstr_fd(dir, fd);
	write (fd, "\n", 1);
	return (0);
}
