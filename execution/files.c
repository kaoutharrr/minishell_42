/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:01:55 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 05:22:57 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*open_files(t_cmd *cmd)
{
	int	*fd;
	int	i;

	i = 0;
	fd = malloc(8);
	fd = files_norm(cmd->files, i, fd);
	return (fd);
}

int	ambigious(t_files *files, int i, char *temp)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (files[i].file[j] == '\0')
		return (-1);
	while (files[i].file[j])
	{
		if (ambigious2(files[i].file, j, k) == -1)
			return (-1);
		j = ambigious2(files[i].file, j, k);
	}
	temp = files[i].file;
	files[i].file = rm_quotes(files[i].file, -1, NULL, NULL);
	free(temp);
	return (1);
}

int	ambigious2(char *file, int j, int k)
{
	if (file[j] <= 32)
		return (-1);
	if (file[j] == '"' || file[j] == '\'')
	{
		k = 0;
		j++;
		while (file[j + k] && file[j - 1] != file[j + k])
			k++;
		j += k + 1;
	}
	else
		j++;
	return (j);
}

int	*files_norm2(t_files *files, int i, int *fd, int j)
{
	if (j == 1)
	{
		ft_putstr_fd(" : ambiguous redirect\n", 2);
		fd[1] = -1;
		fd[0] = -1;
	}
	else if (j == 2)
	{
		fd[0] = in_open(files, i, fd[0]);
		if (fd[0] < 0)
			fd[1] = -1;
	}
	else if (j == 3)
	{
		fd[1] = open_out(files, i, fd[1]);
		if (fd[1] < 0)
			fd[0] = -1;
	}
	return (fd);
}

int	*files_norm(t_files *files, int i, int *fd)
{
	fd[0] = 0;
	fd[1] = 1;
	while (files && files[i].type != -1)
	{
		if (files[i].type != 2 && ambigious(files, i, NULL) == -1)
			return (files_norm2(files, i, fd, 1));
		if (files[i].type == 0 || (files[i].type == 2))
		{
			fd = files_norm2(files, i, fd, 2);
			if (fd[0] < 0)
				break ;
		}
		if (files[i].type == 1 || (files[i].type == 3))
		{
			fd = files_norm2(files, i, fd, 3);
			if (fd[1] < 0)
				break ;
		}
		i++;
	}
	return (fd);
}
