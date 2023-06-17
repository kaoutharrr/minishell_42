/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:31:02 by adadoun           #+#    #+#             */
/*   Updated: 2023/05/21 17:15:26 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"../header.h"

void	ft_lstadd_back_1(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = ft_lstlast_1(*lst);
		temp->next = new;
	}
}
