/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:55:54 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 04:19:31 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	export_process(char **command, int fd)
{
	int		i;
	char	**arr;

	i = 0;
	arr = fill_arr();
	while (arr[i])
		i++;
	selection_sort(arr, i);
	if (!command[1])
	{
		printf_env(arr, fd);
		myfree(arr);
		return (0);
	}
	else
		export1(command);
	myfree(arr);
	return (0);
}

void	printf_env(char **arr, int fd)
{
	t_print	print;

	print.j = 0;
	while (arr[print.j])
	{
		print_env(print, fd, print.j, arr);
		print.j++;
	}
	return ;
}

void	print_env(t_print print, int fd, int j, char **arr)
{
	char	*str ;
	int		i;

	print.split = ft_split(arr[j], '=');
	i = find_first_equal(arr[j], '=');
	if (i < 0)
		str = NULL;
	else
		str = ft_substr(arr[j], i + 1, ft_strlen(arr[j]));
	if (!str)
	{
		if (arr[j][ft_strlen(print.split[0])] == '=')
		{
			print.join = arr[print.j];
			arr[j] = ft_strjoin(print.join, "\"\"");
			free(print.join);
		}
		print.s = ft_strjoin("declare -x ", arr[print.j]);
	}
	else
		infinite_export(&print, str);
	write_free(print, fd);
}

void	write_free(t_print print, int fd)
{
	ft_putstr_fd(print.s, fd);
	write(fd, "\n", 1);
	free(print.s);
	myfree(print.split);
}

int	find_first_equal(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
