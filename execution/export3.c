/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:02:51 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 04:25:31 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	export2(char *command, char *s, char *var)
{
	t_print	print;
	char	**arr;

	print.flag = ft_parse(command);
	no_equal(command, s, print.flag);
	if (print.flag == 2)
	{
		arr = fill_arr();
		if (!search(arr, s))
			s = new_var(s, var);
		else
			s = old_var(arr, s, var);
		if (s && *s)
			ft_lstadd_back(&g_llobal.global, ft_lstnew(s));
		myfree(arr);
		if (s)
			free(s);
	}
	else if (print.flag == 3)
	{
		arr = fill_arr();
		export_add(arr, s, var);
		myfree(arr);
	}
	free(var);
}

void	no_equal(char *command, char *s, int flag)
{
	char	**arr;

	if (flag == 0)
	{
		arr = fill_arr();
		if (!search(arr, command))
			ft_lstadd_back(&g_llobal.global, ft_lstnew(command));
		myfree(arr);
		free(s);
	}
}

void	export1(char **command)
{
	int		i;
	t_print	print;
	char	*str;

	i = 1;
	while (command[i])
	{
		print.j = 0;
		print.flag = ft_parse(command[i]);
		check_flag(print.flag, command[i]);
		print.split = ft_split(command[i], '=');
		if (find_first_equal(command[i], '=') == -1)
			str = ft_substr(command[i], 0, ft_strlen(command[i]));
		else
			str = ft_substr(command[i], find_first_equal(command[i], '=') + 1,
					ft_strlen(command[i]));
		if (!print.flag || print.flag == 3)
			print.s = ft_strdup(print.split[0]);
		if (print.flag == 2)
			print.s = ft_substr(print.split[0], 0,
					find_first_equal(print.split[0], '+'));
		export2(command[i], print.s, str);
		myfree(print.split);
		i++;
	}
}

void	infinite_export(t_print *print, char *str)
{
	print->str1 = ft_strjoin(str, "\"");
	print->str0 = ft_strjoin(print->split[0], "=\"");
	print->s2 = ft_strjoin(print->str0, print->str1);
	print->s = ft_strjoin("declare -x ", print->s2);
	free(print->s2);
	free(print->str0);
	free(print->str1);
	free(str);
}
