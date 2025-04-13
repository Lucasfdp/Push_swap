#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

typedef struct s_data
{
    t_stack *a;
    t_stack *b;
}   t_data;

void    swap(t_stack **stack, char name, int print_op);
void    ss(t_stack **a, t_stack **b);
void    push(t_stack **src, t_stack **dest, char name, int print_op);
void    rotate(t_stack **stack, char name, int print_op);
void    rr(t_stack **a, t_stack **b);
void    reverse_rotate(t_stack **stack, char name, int print_op);
void    rrr(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int     ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack *parse_args(int argc, char **argv);
int	ft_strlen(char *str);
void    free_lst(t_stack *stack);
void    free_on_error(t_stack *stack_a, t_stack *stack_b, char **split);

#endif