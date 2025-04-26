#include "push_swap.h"

void    extracting_array(t_stack **stack_a)
{
    int array[(ft_lstsize(*stack_a))];
    int i;
    int j;

    i = 0;
    j = 0;
    while (stack_a)
    {
        array[i] += (*stack_a) -> value;
        i++;
    }
    while (j <= i)
    {
        write(1, &array[j], 1);
        j++;
    }
}