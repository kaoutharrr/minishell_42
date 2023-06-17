/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:32:36 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/31 20:45:38 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "libft.h"

t_list	*ft_lstnew_env(char	*str)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = str;
	p->next = NULL;
	return (p);
}
