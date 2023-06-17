/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:25:29 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/30 19:15:50 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../header.h"

t_list	*ft_lstlast_env(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
