#include "push_swap.h"

void print_stack(t_stack *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (!(a = parse_args(argc, argv)))
        return (free_on_error(a, b, split), write(2, "Error\n", 6));
    print_stack(a, 'A');
    print_stack(b, 'B');
    push(&a, &b, 'b', 1);
    print_stack(a, 'A');
    print_stack(b, 'B');

    while (a)
    {
        t_stack *temp = a;
        a = a->next;
        free(temp);
    }
    while (b)
    {
        t_stack *temp = b;
        b = b->next;
        free(temp);
    }
    return 0;
}

    // push(&b, &a, 'a', 1);
    // push(&b, &a, 'a', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // print_stack(a, 'A');
    // print_stack(b, 'B');
    // rrr(&a, &b);
    // print_stack(a, 'A');
    // print_stack(b, 'B');
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // print_stack(b, 'B');
    // print_stack(a, 'A');
    // swap(&b, 'b', 1);
    // print_stack(b, 'B');
    // reverse_rotate(&b, 'b', 1);
    // reverse_rotate(&b, 'b', 1);
    // print_stack(b, 'B');
    // push(&b, &a, 'b', 1);
    // print_stack(a, 'A');
    // t_stack *temp = ft_lstlast(b);
    // printf("%i%p", b->value, b);


    // Free memory
    // a = ft_lstnew(3);
    // a->next = ft_lstnew(2);
    // a->next->next = ft_lstnew(5);
    // a->next->next->next = ft_lstnew(8);
    // a->next->next->next->next = ft_lstnew(4);
    // a->next->next->next->next->next = ft_lstnew(1);