/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:26:26 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/07 21:48:55 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	x = 0;
	y = i;
	if (dstsize > 0 && dstsize > i)
	{
		while (src[x] && x < dstsize - i - 1)
		{
			dst[y] = src [x];
			x++;
			y++;
		}
		dst[y] = '\0';
		return (i + j);
	}
	return (j + dstsize);
}
