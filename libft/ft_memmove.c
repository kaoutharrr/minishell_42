/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:58:07 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/06 15:16:30 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	if (src == dst)
		return (d);
	if (s > d)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		i = len - 1;
		while (d && i < len)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
