/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_2dar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:35:49 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 04:13:02 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	nw(char *str, int i, int n, int j)
{
	int	k;

	while (str[i])
	{
		j = 0;
		while (str[i] && str[i + j] && str[i + j] > 32)
		{
			k = 0;
			if (str[i + j] == '"' || str[i + j] == '\'')
			{
				j++;
				while (str[i + j + k] && str[i + j - 1] != str[i + j + k])
					k++;
			}
			j += k + 1;
		}
		if (j != 0)
		{
			i += j;
			n += +1;
		}
		else
			i++;
	}
	return (n);
}

char	**split(char *str, char *mask, int i, int x)
{
	char	**temp;
	int		j;

	mask = creat_mask_n(str, NULL);
	temp = malloc(sizeof(char *) * (nw(str, 0, 0, 0) + 1));
	while (mask[i])
	{
		j = 0;
		while (mask[i + j] && mask[i + j] == '1')
			j++;
		if (j != 0)
		{
			temp[x++] = ft_substr(str, i, j);
			i += j;
		}
		else
			i++;
	}
	temp[x] = NULL;
	free(mask);
	return (temp);
}

char	*split_2dar(t_vars *vars, int n, int i, int j)
{
	char	**str;
	char	**temp;

	temp = NULL;
	n = calculate_str(vars->ar_2d, -1, 0);
	if (n == 0)
	{
		free(vars->ar_2d);
		vars->ar_2d = NULL;
		return (NULL);
	}
	str = malloc(sizeof(char *) * (n + 1));
	while (vars->ar_2d[vars->i_2d])
	{
		temp = split(vars->ar_2d[vars->i_2d], NULL, 0, 0);
		j = 0;
		while (temp[j])
			str[i++] = temp[j++];
		free(temp);
		vars->i_2d++;
	}
	str[i] = NULL;
	ft_free_2d_array(vars->ar_2d);
	vars->ar_2d = str;
	return ("GOOD");
}

int	ft_error(char *input, char *str, int status)
{
	ft_putstr_fd("error : ", 2);
	ft_putstr_fd(str, 2);
	write(1, "\n", 1);
	free(input);
	g_llobal.status = status;
	return (1);
}
