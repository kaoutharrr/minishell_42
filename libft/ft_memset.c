/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:36:38 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/10 02:13:42 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d ;
	size_t			i;

	d = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char ) c ;
		i++;
	}
	return (d);
}
