#ifndef CHECKER_H
#define CHECKER_H
#include "unistd.h"
#include "stdlib.h"
#include <fcntl.h>
#include "get_next_line.h"
typedef struct s_stack
{
    int top;
    int number;
    struct s_stack *next;
}              stack_list;
void	ft_lstadd_front_s(stack_list **lst, stack_list *new);
stack_list	*ft_lstnew_s(int number);
void	ft_lstadd_back_s(stack_list **lst, stack_list *new);
void	ft_lstdelone_s(stack_list *lst);
void	ft_lstclear_s(stack_list **lst);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int stack_size(stack_list *st);
char			*ft_strtrim(char const *s1, char const *set);
int	ft_isdigit(int arg);
void swap(stack_list *st);
void push(stack_list **st_src, stack_list **st_dst);
void rotate(stack_list *st);
void reverse_rotate(stack_list *st);
void pa(stack_list **a, stack_list **b);
void pb(stack_list **a, stack_list **b);
void sa(stack_list *a);
void sb(stack_list *b);
void ss(stack_list *a, stack_list *b);
void pa(stack_list **a, stack_list **b);
void ra(stack_list *a);
void rb(stack_list *b);
void rr(stack_list *a, stack_list *b);
void rra(stack_list *a);
void rrb(stack_list *b);
void rrr(stack_list *a,stack_list *b);
#endif