/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:23:32 by narakely          #+#    #+#             */
/*   Updated: 2021/06/24 19:37:17 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_lstadd_front_s(stack_list **lst, stack_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
stack_list	*ft_lstnew_s(int number)
{
	stack_list		*list;

	if (!(list = malloc(sizeof(stack_list*) * 1)))
		return (NULL);
	(*list).number = number;
	list[0].next = NULL;
	return (list);
}
void	ft_lstadd_back_s(stack_list **lst, stack_list *new)
{
	stack_list *temp;

	temp = *lst;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = new;
		}
	}
}
void	ft_lstdelone_s(stack_list *lst)
{
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}

void	ft_lstclear_s(stack_list **lst)
{
	stack_list *temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone_s(*lst);
			(*lst) = temp;
		}
		lst = NULL;
	}
}

