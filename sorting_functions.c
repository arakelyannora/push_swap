/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:28:31 by narakely          #+#    #+#             */
/*   Updated: 2021/06/24 18:17:56 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(stack_list *st)
{
	if (stack_size(st) == 0)
		return 1;
    while (st->next)
    {
        if (st->number > st->next->number)
            return 0;
        st = st->next;
    }
    return 1;
}
