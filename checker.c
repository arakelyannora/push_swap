/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:55:30 by narakely          #+#    #+#             */
/*   Updated: 2021/06/26 14:55:55 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}
int ft_string_to_int1(char *str)
{
    int is_neg;
    int num;
    
	num = 0;
    if ((is_neg = *str == '-'))
        str++;
    if (ft_strlen(str) > 10)
        ft_error();
    while (*str)
    {
		if (!(ft_isdigit(*str)) || (num == 214748364 && (*str) - 48 > 7 && is_neg == 0) 
				|| (num == 214748364 && (*str) - 48 > 8 && is_neg == 1) || (num > 214748364 && *str))
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
stack_list* fill_stack_small1(char **arg_arr, int length)//, int *res)//, int i_v)//i_v == 1 ete aranc chakertneri, 0 ete chakertnerov
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
void read_instructions(char **line)
{
    char ch;
    t_list		*list;
    t_list *temp;
    int i;
    
    list = NULL;
    while (read(0, &ch, 1) > 0)
		ft_lstadd_back(&list, ft_lstnew(&ch));
    if (!((*line) = (char*)malloc(sizeof(char*) * (ft_lstsize(list) + 1))))
		return ;
	i = 0;
    temp = list;
	while (temp)
	{
		(*line)[i++] = temp->content;
		temp = temp->next;
	}
	ft_lstclear(&list);
	(*line)[i] = '\0';
}
int check_instructions(char **inst)
{
    int i;

    i = 0;
    while (inst[i] != NULL)
    {
        int len = ft_strlen(inst[i]);
        if (ft_strncmp(inst[i], "sa", len) != 0 
            && ft_strncmp(inst[i], "sb", len) != 0
            && ft_strncmp(inst[i], "ss", len) != 0
            && ft_strncmp(inst[i], "pa", len) != 0
            && ft_strncmp(inst[i], "pb", len) != 0
            && ft_strncmp(inst[i], "ra", len) != 0
            && ft_strncmp(inst[i], "rb", len) != 0
            && ft_strncmp(inst[i], "rr", len) != 0
            && ft_strncmp(inst[i], "rra", len) != 0
            && ft_strncmp(inst[i], "rrb", len) != 0
            && ft_strncmp(inst[i], "rrr", len) != 0)
            return (0);     
        i++;      
    }
    return (1);
}
void    execute_instruction(stack_list **a, stack_list **b, char *inst)
{
    if (ft_strncmp(inst, "sa", ft_strlen(inst)) == 0)
        sa((*a));
    else if (ft_strncmp(inst, "sb", ft_strlen(inst)) == 0)
        sb((*b));
    else if (ft_strncmp(inst, "ss", ft_strlen(inst)) == 0)
        ss((*a), (*b));
    else if (ft_strncmp(inst, "pa", ft_strlen(inst)) == 0)
        pa(a, b);
    else if (ft_strncmp(inst, "pb", ft_strlen(inst)) == 0)
        pb(a, b);
    else if (ft_strncmp(inst, "ra", ft_strlen(inst)) == 0)
        ra((*a));
    else if (ft_strncmp(inst, "rb", ft_strlen(inst)) == 0)
        rb((*b));
    else if (ft_strncmp(inst, "rr", ft_strlen(inst)) == 0)
        rr((*a), (*b));
    else if (ft_strncmp(inst, "rra", ft_strlen(inst)) == 0)
        rra((*a));
    else if (ft_strncmp(inst, "rrb", ft_strlen(inst)) == 0)
        rrb((*b));
    else if (ft_strncmp(inst, "rrr", ft_strlen(inst)) == 0)
        rrr((*a), (*b));
}
int check(stack_list **a, stack_list **b, char **inst)
{
    int i;

    i = 0;
    while (inst[i])
    {
        execute_instruction(a, b, inst[i]);
        i++;
    }
    if (is_sorted(*a) && *b == NULL)
        return (1);
    else return (0);
}
void free_(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
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
    stack_list *a = NULL;
    stack_list *b = NULL;
    int i;
    char **arr;
    char *line;
    char **inst;
    
    i = 0;
    if (argc == 2 && argv[1][1] != '\0')
    {
        arr = ft_split(argv[1], ' ');
        a = fill_stack_small1(arr, ft_size(arr));
        read_instructions(&line);
        inst = ft_split(line, '\n');
        if (check_instructions(inst) == 0)
        {
            free_(inst);
            ft_error();
        }
        if (check(&a, &b, inst))
            write(1, "OK\n", 3);
        else write(1, "KO\n", 3);
        free_(arr);
        free(inst);
    }
    else if (argc >= 2)
    {
        a = fill_stack_small(argv, argc);
        read_instructions(&line);
        inst = ft_split(line, '\n');
        if (check_instructions(inst) == 0)
        {
            free_(inst);
            ft_error();
        }
        if (check(&a, &b, inst))
            write(1, "OK\n", 3);
        else write(1, "KO\n", 3);
        free_(inst);
    }
    return (0);
}