#include "push_swap.h"

int    duplicate_num_check(t_stack *stack, int value)
{
    while (stack)
    {
        if (value == stack->value)
            return (1);
    }
    return (0);
}

int valid_num_check(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    if (!num[i])
        return (0);
    while (num[i])
    {
        if (num[i] < '0' || num[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void    free_lst_on_error(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lstnode;

	if (!new || !lst)
		return ;
	lstnode = ft_lstlast(*lst);
	if (!lstnode)
		*lst = new;
	else
		lstnode->next = new;
}