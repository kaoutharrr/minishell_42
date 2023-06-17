/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:47:02 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 16:37:37 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) - start)
	len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) *(len + 1));
	if (!sub)
		return (0);
	while (s && i < len)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
