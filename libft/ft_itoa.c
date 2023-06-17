/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:21:30 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/10 01:04:49 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(long n)
{
	long	count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*ito;
	long	count;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = n;
	count = counter(nbr);
	ito = malloc(sizeof(char) * (count + 1));
	if (!ito)
		return (NULL);
	ito[count--] = '\0';
	if (nbr < 0)
	{
		ito[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		ito[count--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (ito);
}
