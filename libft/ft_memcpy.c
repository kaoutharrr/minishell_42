/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:01:00 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/10 02:25:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned const char			*s;
	unsigned char				*d;
	size_t						i;

	s = (unsigned const char *) src;
	d = (unsigned char *) dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (src == dst)
		return (dst);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
