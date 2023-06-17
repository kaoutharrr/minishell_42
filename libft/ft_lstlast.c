/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:25:29 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/18 02:36:27 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../header.h"

t_cmd	*ft_lstlast_1(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
