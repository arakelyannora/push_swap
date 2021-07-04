/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:02:52 by narakely          #+#    #+#             */
/*   Updated: 2021/06/24 19:37:32 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(stack_list *a)
{
    swap(a);
    if (a)
		a->top = a->number;
    write(1, "sa\n", 3);
}
void sb(stack_list *b)
{
    swap(b);
    if (b)
		b->top = b->number;
    write(1, "sb\n", 3);
}
void ss(stack_list *a, stack_list *b)
{
    swap(a);
    swap(b);
    if (a)
		a->top = a->number;
    if (b)
		b->top = b->number;
    write(1, "ss\n", 3);
}
void pa(stack_list **a, stack_list **b)
{
    push(b, a);
    if (*a)
		(*a)->top = (*a)->number;
    if (*b)
		(*b)->top = (*b)->number;
    write(1, "pa\n", 3);
}
void pb(stack_list **a, stack_list **b)
{
    push(a, b);
    if (*a)
		(*a)->top = (*a)->number;
    if (*b)
		(*b)->top = (*b)->number;
    write(1, "pb\n", 3);
}
void ra(stack_list *a)
{
    rotate(a);
    if (a)
		a->top = a->number;
    write(1, "ra\n", 3);
}
void rb(stack_list *b)
{
    rotate(b);
    if (b)
		b->top = b->number;
    write(1, "rb\n", 3);
}
void rr(stack_list *a, stack_list *b)
{
    rotate(a);
    rotate(b);
    if (a)
		a->top = a->number;
    if (b)
		b->top = b->number;
    write(1, "rr\n", 3);
}
void rra(stack_list *a)
{
    reverse_rotate(a);
    if (a)
		a->top = a->number;
    write(1, "rra\n", 4);
}
void rrb(stack_list *b)
{
    reverse_rotate(b);
    if (b)
		b->top = b->number;
    write(1, "rrb\n", 4);
}
void rrr(stack_list *a,stack_list *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    a->top = a->number;
    b->top = b->number;
    write(1, "rrr\n", 4);
}