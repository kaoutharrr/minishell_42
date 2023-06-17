/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:56:29 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/21 12:06:03 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_env_cmp(char *f, char *s)
{
	size_t	i;
	size_t	n;
	char	*temp;

	i = 0;
	n = ft_strlen(f);
	while (f[i] && s[i] && i < n)
	{
		if (f[i] != s[i])
			return (NULL);
		i++;
	}
	if (i != n)
		return (NULL);
	temp = ft_substr(s, ft_strlen(f), ft_strlen(s));
	return (temp);
}
