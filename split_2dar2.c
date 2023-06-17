/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_2dar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:15:32 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 04:12:40 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	calculate_str2(char **str, int i, int j)
{
	int	k;
	int	z;

	k = 0;
	while (str[i][k + j] && str[i][k + j] > 32)
	{
		z = 0;
		if (str[i][k + j] == '"' || str[i][k + j] == '\'')
		{
			z++;
			while (str[i][k + j + z] && str[i][k + j] != str[i][k + j + z])
				z++;
		}
		k += z + 1;
	}
	return (k);
}

int	calculate_str(char **str, int i, int n)
{
	int	j;
	int	k;

	while (str[++i])
	{
		if (str[i][0] != '\0')
		{
			j = 0;
			while (str[i][j])
			{
				k = calculate_str2(str, i, j);
				if (k != 0)
				{
					j += k;
					n += +1;
				}
				else
					j++;
			}
		}
	}
	return (n);
}

char	*creat_mask_n(char *str, char *mask)
{
	int		i;
	char	c;

	i = 0;
	mask = malloc((sizeof(char) + 1) * ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			mask[i++] = '0';
		else if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i];
			mask[i++] = '1';
			while (str[i] && str[i] != c)
				mask[i++] = '1';
			if (mask[i] == c)
				mask[i++] = '1';
		}
		else
			mask[i++] = '1';
	}
	mask[i] = '\0';
	return (mask);
}

int	special_char(char c)
{
	if (c == '`' || c == '$' || c == '.' || c == '+' || c == '-' || c == '*'
		|| c == '/' || c == '?' || c == '!' || c == '>' || c == '<' || c == ','
		|| c == ';' || c == ':' || c == '\\' || c == '"' || c == '\''
		|| c == '=' || c == '+' || c == '-' || c == ')' || c == '(' || c == '&'
		|| c == '^' || c == '%' || c == '#' || c == '@' || c == ' '
		|| c == '\t')
		return (0);
	else if (c >= 48 && c <= 57)
		return (2);
	return (1);
}
