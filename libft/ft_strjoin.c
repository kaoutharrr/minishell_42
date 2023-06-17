/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:21:23 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 16:37:37 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*stj;

	i = 0;
	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s1);
	stj = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!stj)
		return (0);
	while (s1[i])
	{
		stj[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		stj[i + j] = s2[i];
		i++;
	}
	stj[i + j] = '\0';
	return (stj);
}
