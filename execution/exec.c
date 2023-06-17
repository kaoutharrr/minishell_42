/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:56:36 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 00:42:08 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	exec(t_cmd *cmd, int i)
{
	t_cmd	*tmp;
	int		status;
	t_ex	*exec;

	tmp = cmd;
	if (!before_exec(tmp))
		return ;
	exec = malloc(sizeof(t_ex));
	exec->ji = 0;
	exec->pid = malloc((i + 1) * (sizeof(int)));
	exec->in = 0;
	signal(SIGINT, sighandle);
	signal(SIGQUIT, SIG_IGN);
	if (cmdprocess(exec, cmd, i) == -1)
		return ;
	while (waitpid(exec->pid[exec->ji], &status, 0) != -1)
	{
		if (WIFEXITED(status))
			g_llobal.status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_llobal.status = WTERMSIG(status) + 128;
		exec->ji++;
	}
	free(exec->pid);
	free(exec);
}

int	before_exec(t_cmd *cmd)
{
	if (check_heredoc(cmd) > 16)
	{
		ft_putstr_fd("maximum here-document count exceeded\n", 2);
		return (0);
	}
	if (cmd)
	{
		if (heredoc_process(cmd) == -1)
		{
			return (0);
		}
	}
	return (1);
}

int	cmdprocess(t_ex *exec, t_cmd *cmd, int i)
{
	int	flag;

	exec->ka = 0;
	while (cmd)
	{
		exec->fds = open_files(cmd);
		exec->in = exec->fds[0];
		exec->out = exec->fds[1];
		free(exec->fds);
		flag = process(cmd, &exec, i);
		if (flag == -1)
		{
			ft_putstr_fd("fork: Resource temporarily unavailable\n", 2);
			return (-1);
		}
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
		exec->ka++;
	}
	return (0);
}

void	heredoc_pro(t_files files, int end)
{
	char	*line;
	char	*temp;

	while (1)
	{
		line = readline("$> ");
		if (!line)
		{
			free(files.file);
			break ;
		}
		if (ft_strcmp(line, files.file) == 0)
		{
			free(files.file);
			free(line);
			break ;
		}
		line = heredoc_norm(files.file, line);
		temp = files.file;
		files.file = rm_quotes(files.file, -1, NULL, NULL);
		free(temp);
		ft_putstr_fd(line, end);
		free(line);
	}
	close(end);
}

char	*heredoc_norm(char *file, char *line)
{
	char	*temp;

	if (!should_expand(file))
	{
		temp = line;
		line = expand_her(line);
		free(temp);
	}
	temp = line;
	line = ft_strjoin(line, "\n");
	free(temp);
	return (line);
}
