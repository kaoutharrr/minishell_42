/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:31:02 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/31 20:50:27 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"../header.h"

void	ft_lstadd_back_env(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = ft_lstlast_env(*lst);
		temp->next = new;
	}
}
