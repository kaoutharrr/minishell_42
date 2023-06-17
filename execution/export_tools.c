/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 05:03:11 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 04:03:52 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

char	*old_var(char **arr, char *s, char *var)
{
	char	*join;

	if (search(arr, s))
	{
		if (var)
		{
			join = ft_strjoin(s, "=");
			if (search(arr, join))
			{	
				remove_list(&g_llobal.global, search(arr, join));
				free(s);
				s = ft_strjoin(search(arr, join), var);
			}
			else
				free_export(s, arr, var);
			free(join);
		}
		else
		s = NULL;
	}
	return (s);
}

void	free_export(char *s, char **arr, char *var)
{
	char	*s1;

	remove_list(&g_llobal.global, search(arr, s));
	s1 = ft_strjoin(search(arr, s), "=");
	free(s);
	s = ft_strjoin(s1, var);
	free(s1);
}

char	*new_var(char *s, char *var)
{	
	char	*s1;
	char	*s2;

	s1 = s;
	s2 = ft_strjoin("=", var);
	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s);
}

void	export_add(char **arr, char *s, char *var)
{
	char	*str;

	arr = fill_arr();
	if (search(arr, s))
		remove_list(&g_llobal.global, search(arr, s));
	str = ft_strjoin(s, "=");
	free(s);
	if (var)
	{
		s = ft_strjoin(str, var);
		free(str);
	}
	else
		s = str;
	ft_lstadd_back(&g_llobal.global, ft_lstnew(s));
	free(s);
	myfree(arr);
}

char	*search(char **arr, char *command)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(command, arr[i], ft_strlen(command)))
			return (arr[i]);
		i++;
	}
	return (NULL);
}
