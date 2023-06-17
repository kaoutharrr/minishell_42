/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:32:36 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/18 02:34:45 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "libft.h"

t_cmd	*ft_lstnew_1(int i)
{
	t_cmd	*p;

	i = 0;
	p = malloc(sizeof(t_cmd));
	if (!p)
		return (NULL);
	p->next = NULL;
	return (p);
}
