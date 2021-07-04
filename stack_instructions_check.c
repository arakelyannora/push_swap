/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:34 by narakely          #+#    #+#             */
/*   Updated: 2021/06/24 19:38:20 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}
int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}
int stack_size(stack_list *st)
{
    int size;

    size = 0;
    if (st == NULL)
        return (0);
    while (st)
    {
        size++;
        st = st->next;
    }
    return (size);
}

void swap(stack_list *st)
{
    int tmp;

    if (stack_size(st) > 1)
    {
        tmp  = st->number;
        st->number = st->next->number;
        st->next->number = tmp;
    }
}

void push(stack_list **st_src, stack_list **st_dst)
{
    stack_list *temp;
    if (stack_size((*st_src)))
    {
        ft_lstadd_front_s(st_dst, ft_lstnew_s((*st_src)->number));
        temp = (*st_src)->next;
        ft_lstdelone_s(*st_src);
        *st_src = temp;
    }
}

void rotate(stack_list *st)
{
    int tmp = st->number;
    while (st->next)
    {
       st->number = st->next->number;
       st = st->next;
    }
    st->number = tmp;
}

int rev(stack_list *st)
{
    int tmp, tmp1;
    tmp1 = st->number;
    while (st->next)
    {
       tmp = st->next->number;
       st->next->number = tmp1;
       tmp1 = tmp; 
       st = st->next;
    }
    return (tmp1);
}
void reverse_rotate(stack_list *st)
{
    int tmp;
    tmp = rev(st);
    st->number = tmp;
}