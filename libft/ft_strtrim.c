/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:42:27 by kkouaz            #+#    #+#             */
/*   Updated: 2022/11/08 06:01:41 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mystring(const char *s, size_t len)
{
	size_t	i;
	size_t	x;
	char	*p;

	i = 0;
	x = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (x < len)
		p[x++] = s[i++];
	p[x] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	if (!*s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1 ;
	while (s1[j] && ft_strchr(set, s1[j]) && j > i)
		j--;
	len = j - i + 1;
	return (mystring(&s1[i], len));
}
