/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:58:49 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 19:28:49 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*get_env(char *s)
{
	t_list	*tmp;
	int		i;
	char	*str;

	i = 0;
	tmp = g_llobal.global;
	s = ft_strjoin(s, "=");
	while (tmp && tmp->content)
	{
		if (!ft_strncmp(tmp->content, s, ft_strlen(s)))
		{
			str = tmp->content;
			while (str[i] == s[i])
				i++;
			free(s);
			return (str + i);
		}
		tmp = tmp->next;
	}
	free(s);
	return (NULL);
}

void	remove_list(t_list **head, char *key)
{
	t_list	*temp;
	t_list	*prev;

	temp = *head;
	if (temp != NULL && !ft_strncmp(temp->content, key, ft_strlen(key)))
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && ft_strncmp(temp->content, key, ft_strlen(key)))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	free(temp->content);
	prev->next = temp->next;
	free(temp);
}

int	ft_parse(char *cmd)
{
	int		i;
	int		flag;
	char	**var;
	char	*str;

	str = NULL;
	i = 0;
	flag = 0;
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (1);
	while (cmd[i])
	{
		if (cmd[i] == '=' && cmd[i - 1] == '+')
			flag = 2;
		else if (cmd[i] == '=')
			flag = 3;
		i++;
	}
	var = ft_split(cmd, '=');
	i = 0;
	while (var[0][i++])
		flag = ft_parse2(var, flag, str, i);
	myfree(var);
	return (flag);
}

int	ft_parse2(char **var, int flag, char *str, int i)
{
	int	j;

	if (flag == 2)
		i = i - 1;
	j = 0;
	str = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		str[j] = var[0][j];
		j++;
	}
	str[j] = '\0';
	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (flag);
}

void	selection_sort(char **arr, int n)
{
	int		i;
	int		j;
	int		min;
	char	*temp;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(arr[j], arr[min]) < 0)
				min = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		i++;
	}
}
