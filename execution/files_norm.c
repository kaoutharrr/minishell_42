/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:42:23 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 05:29:36 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	open_out(t_files *files, int i, int fd)
{
	if (files[i].type == 3)
	{
		fd = open(files[i].file, O_CREAT | O_APPEND | O_RDWR, 0644);
	}
	else
		fd = open(files[i].file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
		perror(files[i].file);
	if (checknext(files, 1, i) || checknext(files, 3, i))
		close(fd);
	return (fd);
}

int	checknext(t_files *files, int type, int i)
{
	int	n;

	n = i;
	while (files[i].file)
	{
		i++;
		if (files[i].type == type)
			return (1);
	}
	i = n;
	return (0);
}

int	in_open(t_files *files, int i, int fd)
{
	if (files[i].type == 2)
	{
		fd = files[i].fd;
	}
	else
	{
		files[i].fd = 0;
		fd = open(files[i].file, O_RDONLY, 0644);
		if (fd < 0)
		{
			perror(files[i].file);
		}
	}
	if (checknext(files, 0, i) || checknext(files, 2, i))
		close(fd);
	return (fd);
}
