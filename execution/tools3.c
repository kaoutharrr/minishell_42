/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 03:28:38 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 05:34:31 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t				i;
	unsigned const char	*a1;
	unsigned const char	*a2;

	a1 = (unsigned const char *)s1;
	a2 = (unsigned const char *)s2;
	i = 0;
	while ((a1[i] != '\0' || a2[i] != '\0'))
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}

void	error(char *s, int fd, int ex)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(ex);
}

char	**fill_arr(void)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**arr;

	i = 0;
	j = 0;
	tmp = g_llobal.global;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	arr = malloc(i * ((sizeof(char *)) + 1));
	tmp = g_llobal.global;
	i = 0;
	while (tmp && tmp->content)
	{
		arr[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

t_list	*my_env(char **env)
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	while (env[i])
	{
		ft_lstadd_back(&list, ft_lstnew(env[i]));
		i++;
	}
	return (list);
}

void	not_found(char *s1, char *s2, int ex)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	write(2, "\n", 1);
	exit(ex);
}
