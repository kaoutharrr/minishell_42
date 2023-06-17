/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:06:53 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/15 17:11:24 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_list2(t_list *head)
{
	while (head != NULL)
	{
		head = head->next;
		free(head);
	}
}

void	free_list(t_cmd *head)
{
	while (head != NULL)
	{
		head = head->next;
		free(head);
	}
}

int	**myfree_int(int **p, int size)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (i < size)
	{
		free (p[i]);
		p[i] = (NULL);
		i++;
	}
	free(p);
	p = NULL;
	return (p);
}

char	**myfree(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return (NULL);
	while (p[i])
	{
		free (p[i]);
		p[i] = (NULL);
		i++;
	}
	free(p);
	p = NULL;
	return (p);
}
