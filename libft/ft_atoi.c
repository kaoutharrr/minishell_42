/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:16:26 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/16 23:45:31 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] != 0 && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
		res = res * 10 + (str[i++] - 48);
	atoi_errors(sign, res, str);
	return (res * sign);
}

void	atoi_errors(int sign, unsigned long res, char *str)
{
	if (sign == 1 && res >= 9223372036854775807)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (sign == -1 && res > 9223372036854775807)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
}
