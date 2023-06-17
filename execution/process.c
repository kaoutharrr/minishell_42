/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:40:10 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 00:15:08 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	process(t_cmd *cmd, t_ex **exec, int count)
{
	int		fd[2];
	t_cmd	*tmp;

	tmp = cmd;
	if (tmp->command && tmp->command[0] && is_builtin(tmp->command) == 1
		&& tmp->index == 1 && !tmp->next)
	{
		builtins(tmp->command, (*exec)->out);
		return (0);
	}
	tmp = cmd;
	if (pipe(fd) == -1)
		error("error", 2, 1);
	signal(SIGINT, SIG_IGN);
	(*exec)->pid[(*exec)->ka] = fork();
	if ((*exec)->pid[(*exec)->ka] == 0)
		child_process(cmd, *exec, fd, count);
	if ((*exec)->pid[(*exec)->ka] == -1)
		return (-1);
	close(fd[1]);
	if (dup2(fd[0], 0))
		exit(1);
	close(fd[0]);
	return (0);
}

void	child_process(t_cmd *cmd, t_ex *exec, int *fd, int count)
{
	char	**arr;
	t_cmd	*tmp;

	if (!cmd->command)
		exit(0);
	if (!cmd->command[0])
		ft_close(fd[0], fd[1], 1);
	arr = fill_arr();
	tmp = cmd;
	signal(SIGINT, here_handle);
	signal(SIGQUIT, quithandle);
	if (cmd->index == 1)
	{
		if ((exec)->in == -1)
			exit(1);
	}
	if (cmd->index == count)
		last_cmd(exec->in, exec->out);
	else
		middle_cmd(exec->in, exec->out, fd[1]);
	close(fd[0]);
	close(fd[1]);
	ft_execute(cmd, arr);
}

void	ft_close(int fd1, int fd2, int ex)
{
	close(fd1);
	close(fd2);
	exit(ex);
}

void	last_cmd(int in, int out)
{
	if (in != 0)
		if (dup2(in, 0) == -1)
			exit(1);
	if (out == -1)
		exit(1);
	if (out != 1)
		if (dup2(out, 1) == -1)
			exit(1);
}

void	middle_cmd(int in, int out, int fd)
{
	if (in != 0)
		if (dup2(in, 0) == -1)
			exit(1);
	if (out != 1)
	{
		if (dup2(out, 1) == -1)
			exit(1);
		close(fd);
	}
	else if (dup2(fd, 1) == -1)
		exit(1);
}
