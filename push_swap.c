/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:36:04 by narakely          #+#    #+#             */
/*   Updated: 2021/06/26 14:53:27 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_error()
{
	write(2, "Error\n", 6);
	exit(-1);
}
int ft_string_to_int1(char *str)
{
    int is_neg;
    int num;
    
	num = 0;
    if ((is_neg = *str == '-'))
    {    str++;
		if (*str == '\0')
				ft_error();
	}
    if (ft_strlen(str) > 10)
        ft_error();
    while (*str)
    {
		if (!(ft_isdigit(*str)) || (num == 214748364 && (*str) - 48 > 7 && is_neg == 0) 
				|| (num == 214748364 && (*str) - 48 > 8 && is_neg == 1))
			ft_error();
		num = num * 10 + ((*str) - 48);
		str++;
    }
    return is_neg == 0 ? num : -num; 
}
int is_there_duplicates(const int *arr, const int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length && j != i)
		{
			if (arr[i] == arr[j])
				return 0;
            j++;
		}
		i++;
	}
	return 1;
}
int	arr_is_sorted(int *num_arr, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (num_arr[i] > num_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
void swap1(int *arr, int left, int rigth)
{
	int swap;

	swap = arr[left];
	arr[left] = arr[rigth];
	arr[rigth] = swap;
}
int	partition(int *arr, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			swap1(arr, left, right);
			left++;
			right--;
		}
	}
	return (left);
}
void quick_sort(int *arr, int left, int right)
{
	int pivot;
	int index;
	
	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	index = partition(arr, left, right, pivot);
	quick_sort(arr, left, index - 1);
	quick_sort(arr, index, right);
}
int sort(int *num_arr, int length)
{
	if (arr_is_sorted(num_arr, length - 1))
		return (0);
	quick_sort(num_arr, 0, length - 1);
	return (1);
}
int* copy(int *num_arr, int length)
{
	int i;
	int *copy_arr;

	i = 0;
	copy_arr = (int*)malloc((length - 1) * sizeof(int));
	if (copy_arr == NULL)
		return (NULL);
	while (i < length)
	{	
		copy_arr[i] = num_arr[i];
		i++;
	}
	return (copy_arr);
}
void simplify(int *num_arr, int *copy_arr, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (num_arr[i] == copy_arr[j])
			{	
				num_arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
stack_list* fill_stack(char **arg_arr, int length, int *res)
{
    int i;
	int j;
	int *num_arr;
	int *copy_arr;
	stack_list *st;

    i = 1;
	j = 0;
	st = NULL;
	if (!(num_arr = (int*)malloc((length - 1) * sizeof(int))))
		return NULL;
	while (i < length)
	{
		num_arr[j] = ft_string_to_int1(arg_arr[i]);
		i++;
		j++;
	}
	if (!(is_there_duplicates(num_arr, length - 1)))
	{
		free(num_arr);
		ft_error();
		
	}
	copy_arr = copy(num_arr, length - 1);
	*res = sort(copy_arr, j);
	simplify(num_arr, copy_arr, length - 1);
	i = 0;
    while (i < length - 1)
    {
        ft_lstadd_back_s(&st, ft_lstnew_s(num_arr[i]));
		i++;
    }
	st->top = st->number;
	free(num_arr);
	free(copy_arr);
	return st;
}
stack_list* fill_stack1(char **arg_arr, int length, int *res)
{
    int i;
	int j;
	int *num_arr;
	int *copy_arr;
	stack_list *st;

    i = 0;
	j = 0;
	st = NULL;
	if (!(num_arr = (int*)malloc((length) * sizeof(int))))
		return NULL;
	while (i < length)
	{
		num_arr[j] = ft_string_to_int1(arg_arr[i]);
		i++;
		j++;
	}
	if (!(is_there_duplicates(num_arr, length)))
	{
		free(num_arr);
		ft_error();
	}
	copy_arr = copy(num_arr, length);
	*res = sort(copy_arr, j);
	// for (int k = 0; k < j; k++)
	// 	printf("%d ", copy_arr[k]);
	// printf("\n");
	simplify(num_arr, copy_arr, length);
	// for (int k = 0; k < j; k++)
	// 	printf("%d ", num_arr[k]);
	// printf("\n");
	i = 0;
    while (i < length)
    {
        ft_lstadd_back_s(&st, ft_lstnew_s(num_arr[i]));
		i++;
    }
	st->top = st->number;
	free(num_arr);
	free(copy_arr);
	return st;
}
int	sort_stack(stack_list *a, stack_list *b, int a_size)
{
	int i;
	int j;
	int max_num = a_size - 1;
	int max_bits = 0;
	int check = 1;
	int count = 0;
	
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < a_size && a)
		{
			if (((a->top >> i) & 1) == 1)
				{
					count++;
					ra(a);
				}
			else {
				pb(&a, &b);
				count++;
			}
			j++;
		}
		check = check * 2;
		i++;
	while (stack_size(b) != 0)
		pa(&a, &b);
	}
	return (count);
}
stack_list* fill_stack_small(char **arg_arr, int length)
{
	int i;
	int j;
	int *num_arr;
	stack_list *st;

    i = 1;
	j = 0;
	st = NULL;
	if (!(num_arr = (int*)malloc((length - 1) * sizeof(int))))
		return NULL;
	while (i < length)
	{
		num_arr[j] = ft_string_to_int1(arg_arr[i]);
		i++;
		j++;
	}
	if (!(is_there_duplicates(num_arr, length - 1)))
	{
		free(num_arr);
		ft_error();
	}
	i = 0;
    while (i < length - 1)
    {
        ft_lstadd_back_s(&st, ft_lstnew_s(num_arr[i]));
		i++;
    }
	st->top = st->number;
	free(num_arr);
	return st;
}
stack_list* fill_stack_small1(char **arg_arr, int length)
{
	int i;
	int j;
	int *num_arr;
	stack_list *st;

    i = 0;
	j = 0;
	st = NULL;
	if (!(num_arr = (int*)malloc((length) * sizeof(int))))
		return NULL;
	while (i < length)
	{
		num_arr[j] = ft_string_to_int1(arg_arr[i]);
		i++;
		j++;
	}
	if (!(is_there_duplicates(num_arr, length)))
	{
		free(num_arr);
		ft_error();
	}
	i = 0;
    while (i < length)
    {
        ft_lstadd_back_s(&st, ft_lstnew_s(num_arr[i]));
		i++;
    }
	st->top = st->number;
	free(num_arr);
	return st;
}
void sort_stack_three(stack_list *a)
{
	if (a->number > a->next->number && a->next->number < a->next->next->number && a->number < a->next->next->number)
		sa(a);
	if (a->number < a->next->number && a->next->number > a->next->next->number && a->number < a->next->next->number)
	{
		rra(a);
		sa(a);
	}
	if (a->number < a->next->number && a->next->number > a->next->next->number && a->number > a->next->next->number)
		rra(a);
	if (a->number > a->next->number && a->next->number < a->next->next->number && a->number > a->next->next->number)
		ra(a);
	if (a->number > a->next->number && a->next->number > a->next->next->number && a->number > a->next->next->number)
	{
		ra(a);
		sa(a);
	}
}
void	sort_st_four(stack_list **a, stack_list **b)
{
	pa(a, b);
	if (is_sorted(*a))
		return ;
	else if ((*a)->number > (*a)->next->number && (*a)->number < (*a)->next->next->number)
		sa((*a));
	else if ((*a)->number > (*a)->next->number && (*a)->number > (*a)->next->next->number && (*a)->number < (*a)->next->next->next->number)
	{
		sa((*a));
		pb(a, b);
		sa((*a));
		pa(a, b);
	}
	else if ((*a)->number > (*a)->next->next->next->number)
		ra((*a));
}
void	sort_st_five(stack_list **a, stack_list **b)
{
	pa(a, b);
	if (is_sorted(*a))
		return ;
	else if ((*a)->number > (*a)->next->number && (*a)->number < (*a)->next->next->number)
		sa((*a));
	else if ((*a)->number > (*a)->next->number && (*a)->number > (*a)->next->next->number 
			&& (*a)->number < (*a)->next->next->next->number)
	{
		sa((*a));
		pb(a, b);
		sa((*a));
		pa(a, b);
	}
	else if ((*a)->number > (*a)->next->number && (*a)->number > (*a)->next->next->number 
				&& (*a)->number > (*a)->next->next->next->number && (*a)->number < (*a)->next->next->next->next->number)
	{
		rra((*a));
		sa((*a));
		ra((*a));
		ra((*a));
	}			
	else if ((*a)->number > (*a)->next->next->next->next->number)
		ra((*a));
}
int find_min(stack_list *st)
{
	int min;

	min = 0;
	if (st)
	{
		min = st->number;
		while (st)
		{
			if (st->number < min)
				min = st->number;
			st = st->next;
		}
	}
	return (min);
}
int find_pos(stack_list *st, int num)
{
	int i;

	i = 0;
	while (st->number != num)
	{
		st = st->next;
		i++;
	}
	return (i);
}
void push_b(stack_list **a, stack_list **b, int f)
{
	int i;
	int size;

	size = stack_size(*a);
	if (f == 1)
		i = 2;
	else i = 1;
	while (i)
	{
		while ((*a)->top != find_min(*a))
		{
			if (find_pos(*a, find_min(*a)) < size / 2)
				ra(*a);
			else rra(*a);
		}
		pb(a, b);
		i--;
	}
}
void	sort_stack_four_five(stack_list *a, stack_list *b, int size)
{
	if (size == 4)
	{
		push_b(&a, &b, 0);
		sort_stack_three(a);
		pa(&a, &b);
		pa(&a, &b);
	}
	if (size == 5)
	{
		push_b(&a, &b, 1);
		sort_stack_three(a);
		pa(&a, &b);
		pa(&a, &b);
	}
}
void	sort_stack_small(stack_list *a, stack_list *b, int size)
{
	if (size == 2)
	{
		if (a->number > a->next->number)
			sa(a);
	}
	if (size == 3)
		sort_stack_three(a);
	if (size > 3)
		sort_stack_four_five(a, b, size);
}
int ft_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);	
}
int main(int argc, char** argv)
{
	int res;
	int c = 0;
	char **arr;
	int size;
	int i;

	i = 0;
	stack_list *a = NULL, *b = NULL;
	// printf("%d\n", argc);
	// printf("%c\n", argv[1][0]);
	// printf("%s\n", argv[1]);
	// if (argc == 2 && argv[1][0] == '"')
	// {
	// 	if (argv[1][0] == '"' && argv[1][ft_strlen(argv[1]) - 1] != '"')
	// 		ft_error();
	// 	else {
	// 		argv[1] = ft_strtrim(argv[1], "\"");
	// 		arr = ft_split(argv[1], ' ');
	// 		size = ft_size(arr);
	// 		a = size <= 5 ? fill_stack_small1(arr, size) : fill_stack1(arr, size, &res);
	// 		if (!is_sorted(a))
	// 			size <= 5 ? sort_stack_small(a, b, size) : sort_stack(a, b, size);
	// 		while (arr[i])
	// 		{
	// 			free(arr[i]);
	// 			i++;
	// 		}
	// 		free(arr);
	// 	}
	// }
	if (argc == 2 && argv[1][1] != '\0')
	{
		arr = ft_split(argv[1], ' ');
		size = ft_size(arr);
		a = size <= 5 ? fill_stack_small1(arr, size) : fill_stack1(arr, size, &res);
		if (!is_sorted(a))
			size <= 5 ? sort_stack_small(a, b, size) : sort_stack(a, b, size);
	}
	else if (argc >= 2 && argc <= 6)
	{
		a = fill_stack_small(argv, argc);
		if (!is_sorted(a))
			sort_stack_small(a, b, argc - 1);
	}
	if (argc > 6)
	{
   		stack_list *a = NULL, *b = NULL;
		a = fill_stack(argv, argc, &res);
		if (res == 1)
			c = sort_stack(a, b, argc - 1);
	}
    return (0);
}