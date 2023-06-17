/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:24:54 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 17:11:24 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*head;

	head = malloc(sizeof(struct t_list));
	head->next = NULL;
	head->content = ft_strdup(content);
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int	lstsize(t_list *tmp)
{
	int		count;
	t_list	*lst;

	count = 0;
	lst = tmp;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = NULL;
}
