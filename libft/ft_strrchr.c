/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:29:38 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/07 05:49:06 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char	*s, int c)
{
	char	*str;
	int		len;

	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return (str + len);
		len--;
	}
	return (NULL);
}
