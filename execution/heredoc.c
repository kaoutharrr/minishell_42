/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:22:48 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 23:52:48 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_heredoc(t_cmd *cmd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (cmd)
	{
		i = 0;
		while (cmd && cmd->files && cmd->files[i].type != -1)
		{
			if (cmd->files[i].type == 2)
				count++;
			i++;
		}
		cmd = cmd->next;
	}
	return (count);
}

int	**open_pipes(t_cmd *cmd)
{
	int	count;
	int	**ends;
	int	i;

	i = 0;
	count = check_heredoc(cmd);
	if (!count)
		return (NULL);
	ends = malloc(count * sizeof(int *));
	while (i < count)
	{
		ends[i] = malloc(8);
		i++;
	}
	i = 0;
	while (i < count)
	{
		pipe(ends[i]);
		i++;
	}
	return (ends);
}

int	heredoc_process(t_cmd *cmd)
{
	int		**ends;
	int		a;
	t_cmd	*tmp;
	int		flag;

	flag = 0;
	tmp = cmd;
	ends = open_pipes(tmp);
	a = 0;
	if (!ends)
		return (0);
	tmp = cmd;
	fill_end(cmd, ends);
	cmd = tmp;
	a = check_heredoc(cmd);
	cmd = tmp;
	if (a != 0)
		signal(SIGINT, SIG_IGN);
	if (fork() == 0)
		heredoc_fork(cmd, ends);
	else
		flag = close_heredoc(ends, a, cmd->command);
	myfree_int(ends, a);
	return (flag);
}

int	close_heredoc(int **ends, int a, char **command)
{
	int	status;
	int	i;

	i = 0;
	while (command && i < a)
	{
		close(ends[i][1]);
		i++;
	}
	wait(&status);
	if (WIFSIGNALED(status))
	{
		g_llobal.status = 1;
		return (-1);
	}
	return (0);
}
