/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:24:38 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/08 12:33:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	p = malloc (count * size);
	i = 0;
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
