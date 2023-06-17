/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 04:20:03 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 23:52:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*get_env_value_her(char *str)
{
	char	*variable;
	char	*value;
	t_list	*list;

	list = g_llobal.global;
	variable = ft_strjoin_char(str, '=');
	while (list)
	{
		value = ft_str_env_cmp(variable, list->content);
		if (value)
		{
			free(variable);
			return (value);
		}
		list = list->next;
	}
	free(variable);
	if (value)
		free(value);
	return (NULL);
}

char	*single_dollar_her(t_vars *vars, char *input)
{
	char	*temp;

	if (input[vars->i_her] == '\0' || special_char(input[vars->i_her]) == 0)
	{
		temp = vars->str_her;
		vars->str_her = ft_strjoin_char(vars->str_her, '$');
		if (!vars->str_her)
			return (NULL);
		free(temp);
		return ("Skip");
	}
	else if (special_char(input[vars->i_her]) == 2)
	{
		vars->i_xp++;
		return ("Good");
	}
	else
		return ("Continue");
}

void	detect_variable_her(t_vars *vars, char *input)
{
	char	*variable;
	char	*value;
	int		j;
	char	*temp;
	char	*res;

	res = single_dollar_her(vars, input);
	if (ft_strcmp(res, "Continue") == 0)
	{
		j = 0;
		while (input[vars->i_her + j] && special_char(input[vars->i_her
					+ j]) != 0)
			j++;
		variable = ft_substr(input, vars->i_her, j);
		value = get_env_value(variable);
		if (value)
		{
			temp = vars->str_her;
			vars->str_her = ft_strjoin(vars->str_her, value);
			free(temp);
		}
		free(variable);
		free(value);
		vars->i_her += j;
	}
}

char	*expand_her(char *input)
{
	char	*temp;
	t_vars	vars;

	vars.i_her = 0;
	vars.str_her = malloc(1);
	vars.str_her[0] = '\0';
	while (input[vars.i_her])
	{
		if (input[vars.i_her] == '$')
		{
			vars.i_her++;
			detect_variable_her(&vars, input);
		}
		else
		{
			temp = vars.str_her;
			vars.str_her = ft_strjoin_char(vars.str_her, input[vars.i_her]);
			vars.i_her++;
			free(temp);
		}
	}
	return (vars.str_her);
}

void	heredoc_fork(t_cmd *cmd, int **ends)
{
	int	a;
	int	i;

	signal(SIGINT, here_handle);
	a = 0;
	while (cmd)
	{
		i = 0;
		while (cmd->files[i].type != -1)
		{
			if (cmd->files[i].type == 2)
			{
				close(ends[a][0]);
				heredoc_pro(cmd->files[i], ends[a][1]);
				a++;
			}
			i++;
		}
		cmd = cmd->next;
	}
	exit(0);
}
