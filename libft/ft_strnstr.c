/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:08:22 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/07 05:50:17 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
		{
			return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
